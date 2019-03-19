cmake_minimum_required(VERSION 3.13)
project(app C)

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(src DIR_SRCS)
include_directories(${PROJECT_SOURCE_DIR}/header)

add_executable(app main.c src/m0.c header/m0.h src/m1.c header/m1.h)