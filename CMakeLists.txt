cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(picodoro)

pico_sdk_init()

add_executable(picodoro
        main.c
)

target_link_libraries(picodoro pico_stdlib)

pico_add_extra_outputs(picodoro)
