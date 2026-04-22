cmake_minimum_required(VERSION 3.10)
project(gta2_project_c C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/entities.c
    src/ped.c
)

# Create library
add_library(gta2_c STATIC ${SOURCES})

# Compiler flags for reverse engineering accuracy
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(gta2_c PRIVATE
        -Wall
        -Wextra
        -fpack-struct=1    # Pack structures to match binary layout
        -fno-strict-aliasing
    )
endif()

# Export compile commands for IDE integration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
