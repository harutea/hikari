cmake_minimum_required(VERSION 3.14)

project(hikari)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
