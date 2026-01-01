cmake_minimum_required(VERSION 3.10)
project(ObjectDetectionDemo)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(object_detection object_detection.cpp)
target_link_libraries(object_detection ${OpenCV_LIBS})
