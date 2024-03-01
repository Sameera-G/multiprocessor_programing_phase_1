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

# Phase – 1  (learning diary)

    Self-studies done to grasp the required knowledge about OpenCL reading several e books including the ones recommended by the course. 

### Materials followed,

1.	Guides given by the course (found in Moodle)
    a.	OpenCL Specification and starting guide
    b.	OpenCL Specification Guide
    c.	OpenCL Starting Guide

2.	Video tutorial done by Mr. Praneeth Susarla

### The books currently following are,

    1.	OpenCL in action. (Matthew Scarpino)
    2.	OpenCL programming guide by Aaftab Munshi, Benedict R. Gaster, Timothy G. Mattson, James Fung, Dan Ginsburg.
    3.	OpenCL introduction to installation – www.it-book.info

### Web sites referred,

https://www.codeproject.com/Articles/92788/Introductory-Tutorial-to-OpenCL

### YouTube tutorials

1.	https://www.youtube.com/playlist?list=PLv1Li2u2gg2nZt2IADIcoKRrZS_n25NjG
2.	https://www.youtube.com/playlist?list=PLDivN33Lbf6cLqZ5_i_k0KeMaQKEctMgS
3.	https://www.youtube.com/watch?v=dUET4OuXhL8&list=PL1Us4bt1SfFDjo8GHL1xyI3ia2pHhlZeE&index=61&t=103s
4.	https://www.youtube.com/watch?v=Bwjlzbu-ugU&list=PL1Us4bt1SfFDjo8GHL1xyI3ia2pHhlZeE&index=60
5.	https://www.youtube.com/watch?v=f8jnAuFMnPY&list=PL1Us4bt1SfFDjo8GHL1xyI3ia2pHhlZeE&index=59&t=8s
6.	https://www.youtube.com/watch?v=WwwwIr19feU&list=PL1Us4bt1SfFDjo8GHL1xyI3ia2pHhlZeE&index=56&t=11s
7.	https://www.youtube.com/watch?v=KUTVnxCeC50&list=PL1Us4bt1SfFDjo8GHL1xyI3ia2pHhlZeE&index=55&t=1406s
8.	https://www.youtube.com/watch?v=S-alEZ7IZUQ&list=PL1Us4bt1SfFDjo8GHL1xyI3ia2pHhlZeE&index=54&t=106s
9.	https://www.youtube.com/watch?v=avN0UYAU_X4&list=PL1Us4bt1SfFDjo8GHL1xyI3ia2pHhlZeE&index=53
10.	https://www.youtube.com/watch?v=8skymR6lic4&list=PL1Us4bt1SfFDjo8GHL1xyI3ia2pHhlZeE&index=52&t=395s

### Number of hours worked for studies as an average is 2.5 hours per day. (since February second week)

Including installation of drivers, software, trying different versions of header files and testing code snippets. Finally, I was able to utilize the header files taken from,

    https://github.com/KhronosGroup/OpenCL-Headers/tree/main/CL

Also, I wanted to install the “clang”compler software and it was taken from here,

    https://github.com/llvm/llvm-project/releases/tag/llvmorg-17.0.6

As I saw, cl.h file was 5 months old, and the cl_version.h was two years old. When I was running the code, there was an error related to this cl_version.h file. 

    “I:\Research\Softwares\SoftwareInstallations\oneapi\compiler\latest\include/CL/cl_version.h:22:9: note: '#pragma message: cl_version.h: CL_TARGET_OPENCL_VERSION is not defined. Defaulting to 300 (OpenCL 3.0)'
    22 | #pragma message("cl_version.h: CL_TARGET_OPENCL_VERSION is not defined. Defaulting to 300 (OpenCL 3.0)")
                    |         ^~~~~~~
    hello_world_new.c: In function 'main':”

After referring some documentations, I could manage to solve the error. I think I was solved by the clang compiler and the change of compiling instructions.

