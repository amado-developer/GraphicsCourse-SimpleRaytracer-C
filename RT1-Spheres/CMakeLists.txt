cmake_minimum_required(VERSION 3.17)
project(RT1_Spheres)

set(CMAKE_CXX_STANDARD 20)

add_executable(RT1_Spheres main.cpp Raytracer.cpp Raytracer.h Lib.cpp Lib.h Sphere.cpp Sphere.h Materials.cpp Materials.h)