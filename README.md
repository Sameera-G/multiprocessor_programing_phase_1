# multiprocessor_programing_phase_1
multiprocessor programing phase one code and gpu info extracting codes

the way I compiled this code

# Step 1: Compile the C code and generate an object file
gcc -c hello_world_new.c -I"I:\Research\Softwares\SoftwareInstallations\oneapi\cuda\include" -o hello_world_new.o

# Step 2: Compile the OpenCL kernel file and generate an intermediate representation file
clang -x cl '-cl-std=CL3.0' -I"I:\Research\Softwares\SoftwareInstallations\oneapi\cuda\include" -c hello_world_new.cl -o hello_world_new.cl.o

# Step 3: Link the object file with the OpenCL intermediate representation file and the OpenCL library to create the executable file
gcc hello_world_new.o hello_world_new.cl.o -L"I:\Research\Softwares\SoftwareInstallations\oneapi\cuda\lib\x64" -lOpenCL -o hello_world_new.exe

to see the way it works
Debugging Output: Add debugging output to your OpenCL code to print messages indicating the progress of the program, such as when kernels are launched, when data is transferred, and when computations are completed. This can help you track the execution flow and identify any issues that may arise.


