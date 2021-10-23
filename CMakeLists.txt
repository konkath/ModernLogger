cmake_minimum_required(VERSION 3.20)
project(MichauLogger)

set(CMAKE_CXX_STANDARD 20)

add_executable(MichauLogger main.cpp Logger.cpp Logger.h SimpleClassWithVeryLongName.cpp SimpleClassWithVeryLongName.h)
