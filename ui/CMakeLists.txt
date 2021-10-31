cmake_minimum_required(VERSION 3.21)

project(
  EnglishTutor
  VERSION 1.0.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(
  Qt5
  COMPONENTS
    Widgets REQUIRED
    LinguistTools REQUIRED
)

#
# linguist
#
set(
  TS_FILES
  "assets/lang/zh_tw.ts"
  "assets/lang/zh_cn.ts"
)

qt_create_translation(
  QM_FILES
  ${CMAKE_SOURCE_DIR}
  ${TS_FILES}
)


#
# src
#
add_executable(
  ${CMAKE_PROJECT_NAME}
  ${QM_FILES}
  src/${CMAKE_PROJECT_NAME}.cpp
  "src/MainWindow.cpp"
)

target_include_directories(
  ${CMAKE_PROJECT_NAME}
  PRIVATE "include/"
)

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  PRIVATE Qt5::Widgets
)
