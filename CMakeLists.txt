
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(transformation)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

find_package(OPENGL REQUIRED)
find_package(GLUT REQUIRED)

find_library(COCAO Cocao)

include_directories(
    include
    lib
    ${OPENGL_INCLUDE_DIR}
    ${GLUT_INCLUDE_DIR}
)

add_executable(
    transformation
    src/main.cpp
)

target_link_libraries(
    transformation
    ${OPENGL_LIBRARIES}
    ${COCOA_LIBRARIES}
    ${GLUT_LIBRARIES}
)