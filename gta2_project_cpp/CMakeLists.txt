cmake_minimum_required(VERSION 3.10)
project(gta2_project_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files (placeholder - will be filled when methods are verified from ASM)
set(SOURCES
    # Add .cpp files here when classes with vtable methods are confirmed
)

# Create library (empty for now - header only interface)
add_library(gta2_cpp INTERFACE)

target_include_directories(gta2_cpp INTERFACE ${CMAKE_SOURCE_DIR}/include)

# Compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(gta2_cpp INTERFACE
        -Wall
        -Wextra
        -fno-strict-aliasing
    )
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
