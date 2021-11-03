# CMake version
cmake_minimum_required(VERSION 3.0)

set(projectName "ElementeChimice")
#Project name
project(${projectName})

# Define the search path for header files
include_directories(inc)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Define the executable
add_executable(${PROJECT_NAME}
               inc/ElementChimic.hpp
               inc/Metal.hpp
               inc/Nemetal.hpp 
               src/ElementChimic.cpp
               src/Metal.cpp
               src/Nemetal.cpp
               src/Main.cpp)
