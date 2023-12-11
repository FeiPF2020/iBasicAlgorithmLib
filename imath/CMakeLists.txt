cmake_minimum_required(VERSION 3.16)
project(iMath)
SET(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 14)
find_package(Eigen3 REQUIRED)

add_executable(quaternionToEuler quaternionToEuler.cpp)


