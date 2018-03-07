# Debugging with ddd

[ddd](https://www.gnu.org/software/ddd/manual/html_mono/ddd.html) is a graphical user interface for gdb.
In Linux, it is stared from the command line after openocd:

```
[...]/calliope-project-template$ openocd -f openocd.cfg &
[...]/calliope-project-template$ ddd --gdb --debugger arm-none-eabi-gdb-template
```

In [ddd](https://www.gnu.org/software/ddd/manual/html_mono/ddd.html):

File->Open...
[...]/calliope-project-template/build/calliope-mini-classic-gcc-nosd/source/calliope-project-template

```
GNU DDD 3.3.12 (x86_64-pc-linux-gnu), by Dorothea L(gdb) file
[...]/calliope-project-template/build/calliope-mini-classic-gcc-nosd/source/calliope-project-template
Reading symbols from [...]/calliope-project-template/build/calliope-mini-classic-gcc-nosd/source/calliope-project-template...done.
(gdb) target remote localhost:3333
Remote debugging using localhost:3333
Reset_Handler () at
[...]/calliope-project-template/yotta_modules/mbed-classic/targets/cmsis/TARGET_NORDIC/TARGET_MCU_NRF51822/TOOLCHAIN_GCC_ARM/startup_NRF51822.S:144
```
