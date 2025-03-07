cmake_minimum_required(VERSION 3.10)

project(3DCube VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

include_directories("headers/")

add_executable(3DCube main.cpp ${SOURCES})