# glinfo #
---
The *glinfo* is a program for displaying OpenGL capabilities information of the current system. 
The program was influenced by the program *clinfo*.

The program attempts to query information about all possible enumerate that describes the system capabilities. This means enumerate that is associated with current state of the OpenGL context will not be queried, example *GL_ACTIVE_TEXTURE* since the return value does not say anything about systems capabilities. Whereas the enumerate *GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS* return value describe the system capability, in this cause the number of possible binded textures. See the OpenGL specification for more detail for each enumerate.

# Installation #
----
The program can be installed with the following commands.
```
make
make install
```
Note that is has to be done with *root* privileges.

# Example #
----
The program can be easily executed. Since it does take any argument. See following command.
```
glinfo
```

# Dependencies #
----------------
In order to compile the program, the following Debian packages has to be installed.
```
apt-get install mesa-common-dev
```

## License ##
-------
This project is licensed under the GPL+3 License - see the [LICENSE](LICENSE) file for details