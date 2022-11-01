# haxegitlib
Install haxelibs from an OpenFL Project

## Compiling
Requires CMake.

```console
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Usage
haxegitlib will automatically install all the haxelibs that are listed in Project.xml.

If you specify a ``git`` attribute in a haxelib element, it will also install the specified haxelib from git.
