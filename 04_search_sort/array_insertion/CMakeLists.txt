cmake_minimum_required(VERSION 3.1...3.24)

project(Lab04_HomeWork
        VERSION 1.0
        LANGUAGES CXX)

add_executable(array_insertion
               src/main.cpp
               src/insert.cpp
               src/search_position.cpp
               src/insert_sorted.cpp
               )
