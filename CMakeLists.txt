cmake_minimum_required(VERSION 3.25)
project(fixp LANGUAGES C VERSION 1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

set(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/fixp.c
)

add_library(${CMAKE_PROJECT_NAME} STATIC ${SOURCES})
if(UNIX)
    target_link_libraries(${CMAKE_PROJECT_NAME} m)
endif()

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})