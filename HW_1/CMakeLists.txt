cmake_minimum_required(VERSION 3.20)
project(CSA_HW1)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSA_HW1 main.cpp transport.cpp plane.cpp plane.h transport.h ship.cpp ship.h train.cpp train.h tools.h container.cpp container.h)
