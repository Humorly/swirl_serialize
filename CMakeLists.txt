
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

project ("SerializationTool")
include_directories(boost_1_83_0)

add_executable (SerializationTool "SerializationTool.cpp" "data_declaration.h" "cmdline.h")