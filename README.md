# glinfo
[![Actions Build Status](https://github.com/voldien/glinfo/workflows/glinfo/badge.svg?branch=master)](https://github.com/voldien/glinfo/actions)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![GitHub release](https://img.shields.io/github/release/voldien/glinfo.svg)](https://github.com/voldien/glinfo/releases)

The *glinfo* is a program for displaying OpenGL capabilities information of the current system. 
The program was influenced by both the *clinfo* and *vulkaninfo* program.

## Installation
The program can be installed with the following commands.

```bash
git submodule update --init --recursive
mkdir build && cd build
cmake ..
make
```

## Example
The program can be easily executed. Since it does take any argument. See the following section for an example of how the output data is formatted.
```
./glinfo
VERSION 4.6.0 NVIDIA 525.60.11
SHADING_LANGUAGE_VERSION 4.60 NVIDIA

Not supported extension: GL_VERSION_1_1
GL_VERSION_1_2
        GL_MAX_3D_TEXTURE_SIZE : 16384
        GL_MAX_ELEMENTS_INDICES : 1048576
        GL_MAX_ELEMENTS_VERTICES : 1048576
        GL_TEXTURE_MAX_LEVEL : 1048576
        GL_TEXTURE_MAX_LOD : 1048576

GL_VERSION_1_3
        GL_MAX_CUBE_MAP_TEXTURE_SIZE : 32768
        GL_MAX_TEXTURE_UNITS : 4

GL_VERSION_1_4
        GL_MAX_TEXTURE_LOD_BIAS : 15

GL_VERSION_2_0
        GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS : 192
        GL_MAX_DRAW_BUFFERS : 8
        GL_MAX_FRAGMENT_UNIFORM_COMPONENTS : 4096
        GL_MAX_TEXTURE_COORDS : 8
        GL_MAX_TEXTURE_IMAGE_UNITS : 32
        GL_MAX_VARYING_FLOATS : 124
        GL_MAX_VERTEX_ATTRIBS : 16
        GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS : 32
        GL_MAX_VERTEX_UNIFORM_COMPONENTS : 4096

GL_VERSION_3_0
        GL_MAX_ARRAY_TEXTURE_LAYERS : 2048
        GL_MAX_CLIP_DISTANCES : 8
....
....
```

## Dependencies
### Linux
In order to compile the program, the following Debian packages has to be installed.
```
apt-get install mesa-common-dev libglew-dev libglu1-mesa libglu1-mesa-dev libgl1-mesa-glx libgl1-mesa-dev
```

## License
This project is licensed under the GPL+3 License - see the [LICENSE](LICENSE) file for details