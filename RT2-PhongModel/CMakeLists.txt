cmake_minimum_required(VERSION 3.17)
project(RT2_PhongModel)

set(CMAKE_CXX_STANDARD 20)

add_executable(RT2_PhongModel main.cpp Raytracer.cpp Raytracer.h Lib.cpp Lib.h Sphere.cpp Sphere.h Materials.cpp Materials.h Intersect.cpp Intersect.h Light.cpp Light.h)