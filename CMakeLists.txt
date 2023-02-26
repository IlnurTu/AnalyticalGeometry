cmake_minimum_required(VERSION 3.23)
project(Geo)

set(CMAKE_CXX_STANDARD 20)

add_executable(Geo main.cpp source/Plane.cpp include/Plane.h source/Algoritms.cpp include/Algoritms.h include/FileSystem.h source/FileSystem.cpp)
