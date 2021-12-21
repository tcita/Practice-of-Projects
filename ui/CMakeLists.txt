# Set cmake standard
cmake_minimum_required(VERSION 3.21)

# Set project information
project(
  EnglishAssistant
  VERSION 1.0.0
  LANGUAGES CXX
)

# Add executable
add_executable(${PROJECT_NAME})

# Set c++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set Qt path for windows
if(WIN32)
	set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};C:/Qt/5.12.12/mingw73_64/lib/cmake/")
endif()

# Add subdirectory nlohmann_json
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/json-develop)

# Find Qt package
find_package(
  Qt5
  COMPONENTS
    Widgets REQUIRED
    Network REQUIRED
    LinguistTools REQUIRED
)

#
# Copy crawler from lib to build directory
#
add_custom_command(
  TARGET ${CMAKE_PROJECT_NAME} PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/lib/crawler/crawler.jar ${CMAKE_BINARY_DIR}/lib/crawler/crawler.jar
)

# Setup (.ts) files (Qt linguist)
set(
  TS_FILES
  ${CMAKE_SOURCE_DIR}/assets/lang/en_us.ts
  ${CMAKE_SOURCE_DIR}/assets/lang/zh_cn.ts
  ${CMAKE_SOURCE_DIR}/assets/lang/zh_tw.ts
)

# From: https://doc.qt.io/qt-5.12//qtlinguist-cmake-qt5-add-translation.html
set_source_files_properties(
  ${TS_FILES}
  PROPERTIES
    OUTPUT_LOCATION assets/lang
)

# Compile (.ts) files to (.qm) files (Qt linguist)
qt5_create_translation(
  QM_FILES
  ${CMAKE_SOURCE_DIR}
  ${TS_FILES}
)

# src
target_sources(
  ${CMAKE_PROJECT_NAME}
  PRIVATE ${QM_FILES}
  PRIVATE ${CMAKE_SOURCE_DIR}/src/main.cpp
  PRIVATE ${CMAKE_SOURCE_DIR}/src/MainWindow.cpp
  PRIVATE ${CMAKE_SOURCE_DIR}/src/Crawler.cpp
  PRIVATE ${CMAKE_SOURCE_DIR}/src/OnlineTranslator.cpp
)

# include
target_include_directories(
  ${CMAKE_PROJECT_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/include/
)

#
# Link libraries
#
target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  PRIVATE Qt5::Widgets
  PRIVATE Qt5::Network
  PRIVATE nlohmann_json::nlohmann_json
)
