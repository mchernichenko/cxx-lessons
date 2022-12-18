cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
project(student)

set(CMAKE_CXX_STANDARD 17)

include(doctest.cmake)
add_executable(student 
               test_student.cpp
               Student.cpp 
               Student.h 
               StudentList.cpp 
               StudentList.h
               doctest.h)
               
target_link_libraries(student PRIVATE doctest)