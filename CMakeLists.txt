cmake_minimum_required(VERSION 4.2)
project(exam)

set(CMAKE_CXX_STANDARD 20)

add_executable(exam main.cpp
        Area.h
        Area.cpp
        Zoo.h
        Zoo.cpp
        Animal.h
        Animal.cpp
        Species.h
        Species.cpp
        Visitors.h
        Visitors.cpp
        User.h
        User.cpp
        File.h)
