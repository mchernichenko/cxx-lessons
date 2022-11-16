cmake_minimum_required(VERSION 3.1...3.24)
project(Lab04_Intro
        VERSION 1.0
        LANGUAGES CXX)
add_executable( intro
                src/binary_search.cpp   
                src/linear_search.cpp 
                src/intro.cpp)