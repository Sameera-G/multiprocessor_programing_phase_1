# multiprocessor_programing_phase_1
multiprocessor programing phase one 

# the way I compiled this code

## Compile C code and generate object file
gcc -c hello_world_new.c -I"I:\Research\Softwares\SoftwareInstallations\oneapi\cuda\include" -o hello_world_new.o

## Compile OpenCL kernel file
clang -x cl '-cl-std=CL3.0' -I"I:\Research\Softwares\SoftwareInstallations\oneapi\cuda\include" -c hello_world_new.cl -o hello_world_new.cl.o

## Link object file with OpenCL compiled file to make executable file
gcc hello_world_new.o hello_world_new.cl.o -L"I:\Research\Softwares\SoftwareInstallations\oneapi\cuda\lib\x64" -lOpenCL -o hello_world_new.exe

#  additions tasks

I have tried several other approches to be compatible with opencl.