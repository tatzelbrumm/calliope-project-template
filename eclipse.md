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

`yotta build -G "Eclipse CDT4 - Unix Makefiles"` produces

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

`yotta build -G "Ninja"` produces

    cmaier@DrEvil:~/Hackerspaces/calliope/calliope-project-template/build/calliope-mini-classic-gcc-nosd$ lart
    total 1572
    -rw-rw-r-- 1 cmaier cmaier     224 Mär 12 02:35 yotta_config.json
    -rw-rw-r-- 1 cmaier cmaier    2442 Mär 12 02:35 yotta_config.h
    -rw-rw-r-- 1 cmaier cmaier     820 Mär 12 02:35 yotta_build_info.h
    drwxrwxr-x 3 cmaier cmaier    4096 Mär 12 02:35 ..
    -rw-rw-r-- 1 cmaier cmaier     430 Mär 12 02:35 toolchain.cmake
    -rw-rw-r-- 1 cmaier cmaier   12591 Mär 12 02:35 CMakeLists.txt
    drwxrwxr-x 8 cmaier cmaier    4096 Mär 12 02:35 ym
    drwxrwxr-x 3 cmaier cmaier    4096 Mär 12 02:35 generated
    -rw-rw-r-- 1 cmaier cmaier   16458 Mär 12 02:35 CMakeCache.txt
    -rw-rw-r-- 1 cmaier cmaier     444 Mär 12 02:35 CTestTestfile.cmake
    -rw-rw-r-- 1 cmaier cmaier    1758 Mär 12 02:35 cmake_install.cmake
    -rw-rw-r-- 1 cmaier cmaier    6973 Mär 12 02:35 rules.ninja
    drwxrwxr-x 3 cmaier cmaier    4096 Mär 12 02:35 CMakeFiles
    -rw-rw-r-- 1 cmaier cmaier 1273231 Mär 12 02:35 build.ninja
    drwxrwxr-x 6 cmaier cmaier    4096 Mär 12 02:35 .
    -rw-rw-r-- 1 cmaier cmaier  114860 Mär 12 02:35 .ninja_deps
    drwxrwxr-x 3 cmaier cmaier    4096 Mär 12 02:35 source
    -rw-rw-r-- 1 cmaier cmaier   24025 Mär 12 02:35 .ninja_log


`yotta build -G "Eclipse CDT4 - Ninja"` produces

    cmaier@DrEvil:~/Hackerspaces/calliope/calliope-project-template/build/calliope-mini-classic-gcc-nosd$ lart
    total 1784
    -rw-rw-r-- 1 cmaier cmaier     224 Mär 12 02:25 yotta_config.json
    -rw-rw-r-- 1 cmaier cmaier    2442 Mär 12 02:25 yotta_config.h
    -rw-rw-r-- 1 cmaier cmaier     820 Mär 12 02:25 yotta_build_info.h
    drwxrwxr-x 3 cmaier cmaier    4096 Mär 12 02:25 ..
    -rw-rw-r-- 1 cmaier cmaier     430 Mär 12 02:25 toolchain.cmake
    -rw-rw-r-- 1 cmaier cmaier   12591 Mär 12 02:25 CMakeLists.txt
    drwxrwxr-x 8 cmaier cmaier    4096 Mär 12 02:25 ym
    drwxrwxr-x 3 cmaier cmaier    4096 Mär 12 02:25 generated
    -rw-rw-r-- 1 cmaier cmaier   51321 Mär 12 02:25 CMakeCache.txt
    -rw-rw-r-- 1 cmaier cmaier     444 Mär 12 02:25 CTestTestfile.cmake
    -rw-rw-r-- 1 cmaier cmaier    1758 Mär 12 02:25 cmake_install.cmake
    drwxrwxr-x 3 cmaier cmaier    4096 Mär 12 02:25 CMakeFiles
    -rw-rw-r-- 1 cmaier cmaier    6973 Mär 12 02:25 rules.ninja
    -rw-rw-r-- 1 cmaier cmaier   67595 Mär 12 02:25 .cproject
    -rw-rw-r-- 1 cmaier cmaier 1273627 Mär 12 02:25 build.ninja
    -rw-rw-r-- 1 cmaier cmaier   93587 Mär 12 02:25 .project
    drwxrwxr-x 6 cmaier cmaier    4096 Mär 12 02:25 .
    -rw-rw-r-- 1 cmaier cmaier  114860 Mär 12 02:25 .ninja_deps
    drwxrwxr-x 3 cmaier cmaier    4096 Mär 12 02:25 source
    -rw-rw-r-- 1 cmaier cmaier   24014 Mär 12 02:25 .ninja_log

Eclipse project from one of the `build` directories doesn't work.  
So some files need to be copied from `build` to the top level directory:

    .project
    .cproject

Try with the ninja variant:

In `eclipse`, build in [Targets][exe] - works!

Cleaning up doesn't seem to work that well.  
This may require

    find build -name '*.a' -type f -delete
    find build -name '*.o' -type f -delete
    find build -name '*.obj' -type f -delete

No success with debug so far.
Connecting seems to work, but I get the error message

    Warn : WARNING! The target is already running. All changes GDB did to registers will be discarded! Waiting for target to halt.

Try with the Unix-Makefiles variant:

    .project
    .cproject
    Makefile

need to be copied from the `build/.../ ` directory to top level.

[Targets][clean] works.
[Targets][build] works.

Debug works with the settings:

### OpenOCD setup
Executable: `${openocd_path}/${openocd_executable}`  
GDB port `3333` Telnet port `4444` Config options `-f openocd.cfg`

### GDB Client setup
Executable: `${cross_prefix}`gdb`${cross_suffix}`  
Other options: (none) Commands: `target remote localhost:3333`  

### Startup 
Initial reset type `init`  
`monitor reset init`  
Enable ARM semihosting  

### Run/restart commands
Pre-run/Restart reset. type `halt`  
`monitor reset halt`  
Set breakpoint at `main`  
Continue  
