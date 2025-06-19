cmake_minimum_required(VERSION 3.25)
project(fixptest LANGUAGES C VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(${CMAKE_CURRENT_LIST_DIR}/../CMakeLists.txt)

add_executable(fixptest ${CMAKE_CURRENT_LIST_DIR}/test.c)
target_link_libraries(fixptest fixp)