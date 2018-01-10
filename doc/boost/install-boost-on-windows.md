<font size="7">Build Boost on windows</font>

# Download and Build

we use Boost 1.65.1 over 1.66.0 because with cmake 3.10.1, find_make(Boost 1.66) does not work

## 1. download and unzip

- download boost_1_66_0.7z from http://www.boost.org/users/history/version_1_66_0.html
- unzip to `C:\Dev\boost_1_66_0_src`
  - note that I choose to add a `_src` suffix to distinguish clearly between:
    - build-tree `C:\Dev\boost_1_66_0_src`: from where you build and test boost
    - installation-tree `C:\Dev\boost`: from where you use boost from other projects
- read http://www.boost.org/doc/libs/1_66_0/more/getting_started/windows.html


## 2. bootstrap

in `C:\Dev\boost_1_66_0_src`:
```
bootstrap
```
This will build the `b2.exe` in `C:\Dev\boost_1_66_0_src`

## 3. build the libraries

There are 2 targets for building the boost libraries: `stage` and `install`:
- `stage`
  - is meant for boost internal development, this way you can build and test without impacting other projects on your system
  - builds libs in `C:\Dev\boost_1_66_0_src\stage\lib`
- `ìnstall`
  - is meant for making headers/libs available to other projects on your system
  - let's choose the installation prefix `--prefix=C:\Dev\boost`
  - builds libs in `C:\Dev\boost\lib`
  - copies headers in `C:\Dev\boost\include\boost-1_66`

Let's use `install` because we just want to **use** boost:
```
b2 --prefix=C:\Dev\boost -j8 toolset=msvc-14.1 address-model=64 architecture=x86 link=static threading=multi runtime-link=shared variant=debug,release install
```
Yeah, it's a bit long but it's much better to be specific. Note that I use runtime-link=shared (ie /MD) because it's the default in boost.

where:

|option                  |meaning|
|------------------------|-------|
|`j8`                    |let's use 8 threads to build|
|`address-model=64`      |build 64bits as opposed to 32bits|
|`link=static`           |build static lib as opposed to dll|
|`runtime-link=shared`   |/MD as opposed to /MT|

This compiles 64bits-debug and 64bits-release libs into `C:\Dev\boost\lib`

The lib names have nicely decorated names:

|runtime|variant|decoration|decorated libname example|
|-------|-------|----------|-------|
|shared |release|          |libboost_system-vc141-mt-x64-1_66.lib    |
|shared |debug  |gd        |libboost_system-vc141-mt-gd-x64-1_66.lib |
|static |release|s         |libboost_system-vc141-mt-s-x64-1_66.lib  |
|static |debug  |sgd       |libboost_system-vc141-mt-sgd-x64-1_66.lib|

# Use boost in a project using cmake

Let's create an cmake imported target that will make super easy to use the libs in different cmake projects.
TODO


# Extract a subset of boost using the bcp tool

## Build the optional tools, including the bcp tool

There are a few optional tools that are not built by default.

Build all tools in release:
```
b2 -j8 toolset=msvc-14.1 address-model=64 architecture=x86 link=static threading=multi runtime-link=shared variant=release tools
```

Build all tools in debug:
```
b2 -j8 toolset=msvc-14.1 address-model=64 architecture=x86 link=static threading=multi runtime-link=shared variant=debug tools
```

Build one tool in release (here `bcp`)
```
b2 -j8 toolset=msvc-14.1 address-model=64 architecture=x86 link=static threading=multi runtime-link=shared variant=release tools/bcp
```
Note that when building tools, you have to choose either `debug` or `release`, it's because even if variants are built in different intermediate folders:<br>
`C:\Dev\boost_1_66_0_src\bin.v2\tools\bcp\msvc-14.1\debug\address-model-64\link-static\threadapi-win32\threading-multi\bcp.exe`<br>
`C:\Dev\boost_1_66_0_src\bin.v2\tools\bcp\msvc-14.1\release\address-model-64\link-static\threadapi-win32\threading-multi\bcp.exe`<br>
Then both variants are copied into the same **build-tree** folder with an undecorated name:<br>
`C:\Dev\boost_1_66_0_src\dist\bin\bcp.exe`<br>

## Use bcp

Get info about what polygon depends on, in `C:\Dev\boost_1_66_0_src`:
```
.\dist\bin\bcp.exe --help
.\dist\bin\bcp.exe --list-short polygon
```

Copy the necessary subset of boost to use the polygon lib, in `C:\Dev\boost_1_66_0_src`:
```
mkdir ..\boost_1_66_0_src_polygon_subset
.\dist\bin\bcp.exe polygon ..\boost_1_66_0_src_polygon_subset
```

## Build the subset

Note that `bcp` only copies source files *.hpp/*.cpp, nothing else.
We need other stuff to build the subset from sources
https://stackoverflow.com/questions/28182598/how-to-extract-boostfilesystem-using-bcp

what seems to work is copying files:
- rootdir/*.*
- rootdir/tools/*
- libs/config/*

in `C:\Dev\boost_1_66_0_src_polygon_subset`
```
bootstrap
b2 ...
```
