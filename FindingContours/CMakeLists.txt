cmake_minimum_required(VERSION 3.12)
project(your_project_name)

find_package(OpenCV REQUIRED)

add_executable(your_project_name project_name.cpp)

target_link_libraries(your_project_name ${OpenCV_LIBS})
