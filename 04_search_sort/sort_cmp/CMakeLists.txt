cmake_minimum_required(VERSION 3.0.0)

project(sort_cmp 
        VERSION 0.1.0 
        LANGUAGES CXX)

add_executable(sort_cmp
               src/main.cpp
               src/fill_random.cpp
               src/quick_sort.cpp
               src/selection_sort.cpp
               src/swap.cpp)


