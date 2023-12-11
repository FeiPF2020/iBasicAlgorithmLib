cmake_minimum_required(VERSION 3.16)
project(iOpenGL)
SET(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 14)
find_package(Eigen3 REQUIRED)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

