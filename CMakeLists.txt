# Define project and CMake version
project(CrazyClient)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

# Find dependencies

# Dependencies

# Declare and configure executable
add_executable(crazyclient "src/crazyclient.cpp")
target_include_directories(crazyclient
        PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
    )

target_link_directories(crazyclient PRIVATE ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(crazyclient PRIVATE NatNet)