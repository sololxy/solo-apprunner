cmake_minimum_required(3.9)
project(solo-apprunner)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(test)
