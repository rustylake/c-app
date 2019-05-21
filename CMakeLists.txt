cmake_minimum_required(VERSION 3.13)
project(app C)

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(src DIR_SRCS)
include_directories(${PROJECT_SOURCE_DIR}/header)

add_executable(app main.c src/m0.c header/m0.h src/1/m1.c header/1/m1.h src/2/m2.c header/2/m2.h src/2/m21.c header/2/m21.h src/2/m22.c header/2/m22.h src/model/model.c header/model/model.h src/3/m3.c header/3/m3.h src/model/user.c header/model/user.h src/2/m23.c header/2/m23.h src/model/goods.c header/model/goods.h src/test.c header/test.h src/4/m40.c header/4/m40.h src/3/m31.c header/3/m31.h src/4/m4.c header/4/m4.h src/4/m41.c header/4/m41.h src/4/m42.c header/4/m42.h src/3/m32.c header/3/m32.h src/model/list.c header/model/list.h)