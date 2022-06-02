# glinfo
[![Actions Build Status](https://github.com/voldien/glinfo/workflows/glinfo/badge.svg?branch=master)](https://github.com/voldien/glinfo/actions)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![GitHub release](https://img.shields.io/github/release/voldien/glinfo.svg)](https://github.com/voldien/glinfo/releases)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/voldien/glinfo.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/voldien/glinfo/context:cpp)

The *glinfo* is a program for displaying OpenGL capabilities information of the current system. 
The program was influenced by the program *clinfo*.

The program attempts to query information about all possible enumerate that describes the system capabilities. This means enumerate that is associated with the current state of the OpenGL context will not be queried, for example *GL_ACTIVE_TEXTURE* since the return value does not say anything about systems capabilities. Whereas the enumerate *GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS* return value describes the system capability, which in this case is the number of possible number of binded textures. See the OpenGL specification for more detail for each enumerate.

## Installation
The program can be installed with the following commands.
```
mkdir build
cd build
cmake ..
make
```

## Example
The program can be easily executed. Since it does take any argument. See the following section for an example of how the output data is formatted.
```
./glinfo
RENDERER GeForce GTX 1070 with Max-Q Design/PCIe/SSE2
VENDOR NVIDIA Corporation
VERSION 4.6.0 NVIDIA 450.66
SHADING_LANGUAGE_VERSION 4.60 NVIDIA

GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS : 16
GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS : 96
GL_MAX_COMPUTE_UNIFORM_BLOCKS : 14
GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS : 32
GL_MAX_COMPUTE_UNIFORM_COMPONENTS : 2048
GL_MAX_COMPUTE_ATOMIC_COUNTERS : 16384
GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS : 8
....
....
```

## Dependencies
### Linux
In order to compile the program, the following Debian packages has to be installed.
```
apt-get install mesa-common-dev libglew-dev
```

## License
This project is licensed under the GPL+3 License - see the [LICENSE](LICENSE) file for details