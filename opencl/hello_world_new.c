/*# -----------------------------------------------------------------------------
# Manuel Lage Cañellas (CMVS - University of Oulu).
# Multiprocessor programming course 2024
#
# -----------------------------------------------------------------------------
*/

/*
Example of where you can find your OpenCL based on your SDK
NVIDIA Linux
Linker:     /usr/local/cuda-11.6/lib64/libOpenCL.so
Directory:  /usr/local/cuda-11.6/include

NVIDIA Windows
Linker:     Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.6\lib\x64\OpenCl.lib
Directory:  Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.6\include

Intel CPU Linux
Linker:      /opt/intel/system_studio_2020/opencl/SDK/lib64/libOpenCl.so
Directory:   opt/intel/system_studio_2020/opencl/SDK/include

Intel Graphics Linux
install intel-opencl-icd

*/

#define CL_TARGET_OPENCL_VERSION 300
#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

int main() {
    cl_int           err;
    cl_uint          num_platforms;
    cl_platform_id  *platforms;
    cl_device_id     device;
    cl_context       context;
    cl_command_queue queue;
    cl_program       program;
    cl_kernel        kernel;
    cl_mem           output;

    char result[13];

    // PLATFORM
    int num_max_platforms = 1;
    err = clGetPlatformIDs(num_max_platforms, NULL, &num_platforms);
    printf("Num platforms detected: %d\n", num_platforms);

    platforms = (cl_platform_id*) malloc(sizeof(cl_platform_id) * num_platforms);
    err = clGetPlatformIDs(num_max_platforms, platforms, &num_platforms);

    if(num_platforms < 1) {
        printf("No platform detected, exit\n");
        exit(1);
    }

    // DEVICE
    err = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL, 1, &device, NULL);

    // CONTEXT
    context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);

    // QUEUE
    cl_queue_properties properties = 0;
    queue = clCreateCommandQueueWithProperties(context, device, &properties, &err);

    // READ KERNEL AND COMPILE IT
    FILE *fp;
    char *source_str;
    size_t source_size;

    fp = fopen("hello_world_new.cl", "r");
    if (!fp) {
        fprintf(stderr, "Failed to load kernel.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    source_size = ftell(fp);
    rewind(fp);
    source_str = (char*)malloc(source_size + 1);
    source_str[source_size] = '\0';
    fread(source_str, 1, source_size, fp);
    fclose(fp);

    program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &err);
    free(source_str);
    if (!program) {
        printf("Error: Failed to create compute program!\n");
        exit(1);
    }
    err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);

    // CREATE KERNEL AND KERNEL PARAMETERS
    kernel = clCreateKernel(program, "hello", &err);
    output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, 13 * sizeof(char), NULL, &err);
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &output);

    // EXECUTE KERNEL!
    size_t global_size = 1;
    err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &global_size, NULL, 0, NULL, NULL);

    // READ KERNEL OUTPUT
    err = clEnqueueReadBuffer(queue, output, CL_TRUE, 0, 13 * sizeof(char), result, 0, NULL, NULL);
    printf("***%s***\n", result);

    // Free memory
    clReleaseMemObject(output);
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);
    free(platforms);

    return 0;
}
