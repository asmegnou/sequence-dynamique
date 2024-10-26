cmake_minimum_required(VERSION 3.5)

project(sequence_dynamique LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
add_compile_options(-Wall -Wpedantic)
endif()

add_executable(sequence_dynamique main.cpp sequence.cc sequence.hh)

install(TARGETS sequence_dynamique
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
