cmake_minimum_required(VERSION 3.22)

project(rus-paint)

add_executable(rus-paint
    src/GT.cpp
    src/Main.cpp
    src/main.cpp
)

find_package(X11 REQUIRED)
target_link_libraries(rus-paint PRIVATE ${X11_LIBRARIES})