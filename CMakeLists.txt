cmake_minimum_required(VERSION 3.23)
project(Geo)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE Release)

set(BUILD_SHARED_LIBS OFF)

set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++")

add_executable(Geo main.cpp source/Plane.cpp include/Plane.h source/Algoritms.cpp include/Algoritms.h include/FileSystem.h source/FileSystem.cpp include/Matrix.h)
