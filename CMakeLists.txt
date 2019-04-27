cmake_minimum_required(VERSION 3.13)
project(app C)

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(src DIR_SRCS)
include_directories(${PROJECT_SOURCE_DIR}/header)

add_executable(app main.c src/m0.c header/m0.h src/m1.c header/m1.h src/m2.c header/m2.h src/m21.c header/m21.h src/m22.c header/m22.h src/model.c header/model.h src/m3.c header/m3.h src/user.c header/user.h src/m23.c header/m23.h)