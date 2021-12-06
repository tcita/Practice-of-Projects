cmake_minimum_required(VERSION 3.21)

project(
  EnglishAssistant
  VERSION 1.0.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#
# set path for windows
#
if(WIN32)
	set(CMAKE_PREFIX_PATH "C:/Qt/5.12.12/mingw73_64/lib/cmake")
endif()

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
  "assets/lang/en_us.ts"
)

qt5_create_translation(
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
  "src/main.cpp"
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
