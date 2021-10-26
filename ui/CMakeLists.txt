cmake_minimum_required(VERSION 3.21.3)
project(EnglishTutor VERSION 1.0.0 LANGUAGES CXX)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${CMAKE_PROJECT_NAME}
               src/${CMAKE_PROJECT_NAME}.cpp
               src/MainWindow.cpp)

target_include_directories(${CMAKE_PROJECT_NAME}
                           PRIVATE include)

target_link_libraries(${CMAKE_PROJECT_NAME}
                      PRIVATE Qt5::Widgets)
