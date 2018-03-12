# Using eclipse

Find options that can be used for building targets

    yotta build --help

The interesting targets are 

    -G "Ninja"
    -G "Unix Makefiles"
    -G Eclipse CDT4 - Ninja"
    -G "Eclipse CDT4 - Unix Makefiles"

where `-G "Ninja"` is the default.

    yotta clean
    yotta target calliope-mini-classic-gcc-nosd
    yotta update

`yotta build -g -G` [...] seems to build only `CMakeLists.txt` files.

    yotta build -G "Eclipse CDT4 - Unix Makefiles"
    [...]
    info: a project file has been generated at ./build/calliope-mini-classic-gcc-nosd/.project

`yotta build -G "Unix Makefiles"` produces  

    cmaier@DrEvil:~/Hackerspaces/calliope/calliope-project-template/build/calliope-mini-classic-gcc-nosd$ lart
    total 164
    -rw-rw-r-- 1 cmaier cmaier  2442 Mär 12 02:14 yotta_config.h
    -rw-rw-r-- 1 cmaier cmaier   820 Mär 12 02:14 yotta_build_info.h
    drwxrwxr-x 3 cmaier cmaier  4096 Mär 12 02:14 ..
    -rw-rw-r-- 1 cmaier cmaier   224 Mär 12 02:14 yotta_config.json
    -rw-rw-r-- 1 cmaier cmaier   430 Mär 12 02:14 toolchain.cmake
    -rw-rw-r-- 1 cmaier cmaier 12591 Mär 12 02:14 CMakeLists.txt
    drwxrwxr-x 8 cmaier cmaier  4096 Mär 12 02:14 ym
    drwxrwxr-x 3 cmaier cmaier  4096 Mär 12 02:14 generated
    -rw-rw-r-- 1 cmaier cmaier 16609 Mär 12 02:14 CMakeCache.txt
    -rw-rw-r-- 1 cmaier cmaier  8127 Mär 12 02:14 Makefile
    -rw-rw-r-- 1 cmaier cmaier   444 Mär 12 02:14 CTestTestfile.cmake
    -rw-rw-r-- 1 cmaier cmaier  1758 Mär 12 02:14 cmake_install.cmake
    drwxrwxr-x 6 cmaier cmaier  4096 Mär 12 02:14 .
    drwxrwxr-x 3 cmaier cmaier  4096 Mär 12 02:14 source
    drwxrwxr-x 4 cmaier cmaier  4096 Mär 12 02:14 CMakeFiles

'yotta build -G "Eclipse CDT4 - Unix Makefiles"` produces

    cmaier@DrEvil:~/Hackerspaces/calliope/calliope-project-template/build/calliope-mini-classic-gcc-nosd$ lart
    total 372
    -rw-rw-r-- 1 cmaier cmaier   224 Mär 12 02:17 yotta_config.json
    -rw-rw-r-- 1 cmaier cmaier  2442 Mär 12 02:17 yotta_config.h
    -rw-rw-r-- 1 cmaier cmaier   820 Mär 12 02:17 yotta_build_info.h
    drwxrwxr-x 3 cmaier cmaier  4096 Mär 12 02:17 ..
    -rw-rw-r-- 1 cmaier cmaier   430 Mär 12 02:17 toolchain.cmake
    -rw-rw-r-- 1 cmaier cmaier 12591 Mär 12 02:17 CMakeLists.txt
    drwxrwxr-x 8 cmaier cmaier  4096 Mär 12 02:17 ym
    drwxrwxr-x 3 cmaier cmaier  4096 Mär 12 02:17 generated
    -rw-rw-r-- 1 cmaier cmaier 51475 Mär 12 02:17 CMakeCache.txt
    -rw-rw-r-- 1 cmaier cmaier  8127 Mär 12 02:17 Makefile
    -rw-rw-r-- 1 cmaier cmaier   444 Mär 12 02:17 CTestTestfile.cmake
    -rw-rw-r-- 1 cmaier cmaier  1758 Mär 12 02:17 cmake_install.cmake
    -rw-rw-r-- 1 cmaier cmaier 67700 Mär 12 02:17 .cproject
    -rw-rw-r-- 1 cmaier cmaier 93589 Mär 12 02:17 .project
    drwxrwxr-x 6 cmaier cmaier  4096 Mär 12 02:17 .
    drwxrwxr-x 3 cmaier cmaier  4096 Mär 12 02:18 source
    drwxrwxr-x 4 cmaier cmaier  4096 Mär 12 02:18 CMakeFiles

i.e., extra `.cproject` and `.project` files.


