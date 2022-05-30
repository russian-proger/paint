cmake_minimum_required(VERSION 3.22)

project(paint)

add_executable(paint
    src/GT.cpp
    src/Main.cpp
    src/main.cpp
)

find_package(X11 REQUIRED)
target_link_libraries(paint PRIVATE ${X11_LIBRARIES})