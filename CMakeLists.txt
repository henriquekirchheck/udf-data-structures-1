cmake_minimum_required(VERSION 4.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS On)

if(NOT PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  # Git auto-ignore out-of-source build directory
  file(GENERATE OUTPUT .gitignore CONTENT "*")
endif()

set(CMAKE_C_STANDARD 90)
set(CMAKE_CXX_STANDARD_REQUIRED On)

project(udf-data_structures VERSION 0.1.0 LANGUAGES C)

add_subdirectory(lib/product-array)

add_executable(Exercise01_04-01)
target_sources(Exercise01_04-01 PRIVATE bin/2026-04-01/ex01.c)

add_executable(Exercise02_04-01)
target_sources(Exercise02_04-01 PRIVATE bin/2026-04-01/ex02.c)

add_executable(Exercise03_04-01)
target_sources(Exercise03_04-01 PRIVATE bin/2026-04-01/ex03.c)
target_link_libraries(Exercise03_04-01 PRIVATE ProductArray)
