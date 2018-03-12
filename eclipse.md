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


