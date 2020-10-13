cmake_minimum_required(VERSION 3.17)
project(Lab3_Stereographic)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab3_Stereographic main.cpp Raytracer.cpp Raytracer.h Lib.cpp Lib.h Sphere.cpp Sphere.h Materials.cpp Materials.h Intersect.cpp Intersect.h Light.cpp Light.h Plane.cpp Plane.h Texture.h Texture.cpp)