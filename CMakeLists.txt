cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

# Project name
project(blink)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# filelist
#src
aux_source_directory(./main      SRC_main )
aux_source_directory(./hal/spi   SRC_spi  )
aux_source_directory(./app/blink SRC_blink)
#inc
include_directories (./main
                     ./hal/spi
                     ./app/blink)

# rest of your project
add_executable(blink ${SRC_main} ${SRC_spi} ${SRC_blink})

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(blink pico_stdlib hardware_spi)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(blink)
