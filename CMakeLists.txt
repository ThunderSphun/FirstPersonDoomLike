cmake_minimum_required(VERSION 3.22)
project(FirstPersonDoomLike C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(SDL)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} SDL3::SDL3)