cmake_minimum_required(VERSION 3.14)
project(lab4_Exception)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab4_Exception
        main.cpp
        MyException.h)
