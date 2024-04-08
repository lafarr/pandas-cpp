cmake_minimum_required(VERSION 3.22)
project(pandas)
set(CMAKE_CXX_STANDARD)
set(CMAKE_CXXFLAGS "-std=c++20 -O3")
# add_library(pandas lib/main.cpp)
add_executable(pandas lib/main.cpp
        include/DataFrame.h
        util/utils.hpp
        lib/DataFrame.cpp
        include/pandas.hpp
        util/utils.cpp
        lib/pandas.cpp
)
set_target_properties(pandas PROPERTIES RUNTIME_OUTPUT_DIRECTORY /home/james/dev/pandas-cpp/bin)