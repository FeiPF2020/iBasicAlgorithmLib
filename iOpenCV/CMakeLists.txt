cmake_minimum_required(VERSION 3.16)
project(iOpenCV)
SET(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 14)
find_package(Eigen3 REQUIRED)

find_package(OpenCV 3 REQUIRED)
add_executable(rotation rotation.cpp)
target_link_libraries(rotation ${OpenCV_LIBS})

