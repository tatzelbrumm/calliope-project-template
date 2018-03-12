# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# compile CXX with /usr/bin/arm-none-eabi-g++
CXX_FLAGS =  -fno-exceptions -fno-unwind-tables -ffunction-sections -fdata-sections -Wall -Wextra -fno-rtti -fno-threadsafe-statics -mcpu=cortex-m0 -mthumb -D__thumb2__ -std=c++11 -fwrapv -Os -g -gdwarf-3 -DNDEBUG   -DTOOLCHAIN_GCC -DTOOLCHAIN_GCC_ARM -DMBED_OPERATORS -DNRF51 -DTARGET_NORDIC -DTARGET_M0 -D__MBED__=1 -DMCU_NORDIC_16K -DTARGET_NRF51_CALLIOPE -DTARGET_MCU_NORDIC_16K -DTARGET_MCU_NRF51_16K_S110  -DTARGET_NRF_LFCLK_RC -DTARGET_MCU_NORDIC_16K -D__CORTEX_M0 -DARM_MATH_CM0 -DNO_BLE -include "/home/cmaier/Hackerspaces/calliope/calliope-project-template/build/calliope-mini-classic-gcc-nosd/yotta_config.h"

CXX_DEFINES = -DYOTTA_MODULE_NAME=microbit

CXX_INCLUDES = -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/build/calliope-mini-classic-gcc-nosd/generated/include -I/home/cmaier/Hackerspaces/calliope/calliope-project-template -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/microbit -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/microbit-dal -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/ble -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/ble-nrf51822 -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/microbit/inc -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/microbit-dal/inc/core -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/microbit-dal/inc/types -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/microbit-dal/inc/drivers -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/microbit-dal/inc/bluetooth -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/microbit-dal/inc/platform -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/api -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/hal -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/cmsis -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/ble-nrf51822/source/btle -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/ble-nrf51822/source/btle/custom -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/ble-nrf51822/source/common -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/ble/ble_radio_notification -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/ble/ble_services/ble_dfu -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/ble/common -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/ble/device_manager -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/ble/device_manager/config -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/ble/peer_manager -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/device -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/drivers_nrf/ble_flash -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/drivers_nrf/delay -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/drivers_nrf/hal -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/drivers_nrf/pstorage -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/drivers_nrf/pstorage/config -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/libraries/bootloader_dfu -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/libraries/bootloader_dfu/hci_transport -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/libraries/crc16 -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/libraries/hci -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/libraries/scheduler -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/libraries/timer -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/libraries/util -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/libraries/fds -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/libraries/fstorage -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/libraries/experimental_section_vars -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/softdevice/common/softdevice_handler -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/softdevice/s130/headers -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/nrf51-sdk/source/nordic_sdk/components/toolchain -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822 -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/TARGET_NRF51_CALLIOPE -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/Lib -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/Lib/s130_nrf51822_1_0_0 -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/Lib/s110_nrf51822_8_0_0 -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/Lib/nordic_sdk -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/Lib/nordic_sdk/components -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/Lib/nordic_sdk/components/libraries -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/Lib/nordic_sdk/components/libraries/crc16 -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/Lib/nordic_sdk/components/libraries/scheduler -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/Lib/nordic_sdk/components/libraries/util -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/cmsis/TARGET_NORDIC -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/cmsis/TARGET_NORDIC/TARGET_MCU_NRF51822 -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/cmsis/TARGET_NORDIC/TARGET_MCU_NRF51822/TOOLCHAIN_GCC_ARM -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/mbed-classic/targets/cmsis/TARGET_NORDIC/TARGET_MCU_NRF51822/TOOLCHAIN_GCC_ARM/TARGET_MCU_NRF51_16K_S110 -I/home/cmaier/Hackerspaces/calliope/calliope-project-template/yotta_modules/microbit/source 

