####################################################################################################
# Project setting
####################################################################################################
# Set cmake standard
cmake_minimum_required(VERSION 3.21.3)

# Set c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# JNI gcc flag #debug!!
SET(CMAKE_CXX_FLAGS "-I\"C:/Program Files/Java/jdk1.8.0_202/include\" -I\"C:/Program Files/Java/jdk1.8.0_202/include/win32\"")
SET(CMAKE_EXE_LINKER_FLAGS "-L \"C:/Program Files/Java/jdk1.8.0_202/jre/bin/server\" -ljvm")

# Set project information
project(
  EnglishAssistant
  VERSION 1.0.0
  LANGUAGES CXX
)

# Windows only
if(WIN32)
  set(QTDIR "C:/Qt/5.15.2/mingw81_64/")
  # Qt cmake config directory
	set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${QTDIR}lib/cmake/")
endif()


####################################################################################################
# Find package
####################################################################################################
# ``JNI_INCLUDE_DIRS``
#   the include dirs to use
# ``JNI_LIBRARIES``
#   the libraries to use (JAWT and JVM)
# ``JNI_FOUND``
#   TRUE if JNI headers and libraries were found.
# Find JNI package
# find_package(
#   JNI REQUIRED
# )

# Find Qt package
find_package(
  Qt5 REQUIRED
  COMPONENTS
    Core
    Widgets
    Network
    LinguistTools
)

# get_target_property(
#   dirs
#   JNI
#   INTERFACE_INCLUDE_DIRECTORIES
# )
# message(">>>>>>>>>>"${dirs})

# Add subdirectory nlohmann_json
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/json-develop)

####################################################################################################
# Build setting
####################################################################################################
# Add executable
add_executable(${CMAKE_PROJECT_NAME})

# Setup (.ts) files
set(
  TS_FILES
  ${CMAKE_SOURCE_DIR}/assets/lang/en_US.ts
  ${CMAKE_SOURCE_DIR}/assets/lang/zh_CN.ts
  ${CMAKE_SOURCE_DIR}/assets/lang/zh_TW.ts
)

# Set output directory
# From: https://doc.qt.io/qt-5.12//qtlinguist-cmake-qt5-add-translation.html
set_source_files_properties(
  ${TS_FILES}
  PROPERTIES
    OUTPUT_LOCATION assets/lang
)

# If the (.ts) file is missing, automatically create a new one
# Compile (.ts) files to (.qm) files (Qt linguist)
qt5_create_translation(
  QM_FILES
  ${CMAKE_SOURCE_DIR}
  ${TS_FILES}
  OPTIONS
    -no-obsolete
)

# include
target_include_directories(
  ${CMAKE_PROJECT_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/include/
  PRIVATE ${JNI_INCLUDE_DIRS}
)

# src
target_sources(
  ${CMAKE_PROJECT_NAME}
  PRIVATE ${QM_FILES}
  PRIVATE ${CMAKE_SOURCE_DIR}/src/main.cpp
  PRIVATE ${CMAKE_SOURCE_DIR}/src/MainWindow.cpp
  PRIVATE ${CMAKE_SOURCE_DIR}/src/Crawler.cpp
  PRIVATE ${CMAKE_SOURCE_DIR}/src/OnlineTranslator.cpp
  PRIVATE ${CMAKE_SOURCE_DIR}/src/Solution.cpp
)

#
# Link libraries
#
target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  PRIVATE Qt5::Core
  PRIVATE Qt5::Gui
  PRIVATE Qt5::Widgets
  PRIVATE Qt5::Network
  PRIVATE nlohmann_json
  PRIVATE ${JNI_LIBRARIES}
)

####################################################################################################
# Copy files
####################################################################################################
# Copy crawler to build directory
add_custom_command(
  TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/lib/crawler ${CMAKE_BINARY_DIR}/lib/crawler
)

# Copy image to build directory
add_custom_command(
  TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets/image ${CMAKE_BINARY_DIR}/assets/image
)

# Copy image to build directory
add_custom_command(
  TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/lib/jsoup ${CMAKE_BINARY_DIR}/lib/jsoup
)

# Copy Qt binary # Problem: plugin binary didn't copied
# From: https://riptutorial.com/cmake/example/29468/qt5-dll-copy-example
# add_custom_command(
#   TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>
#   COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>
#   COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>
#   COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Network> $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>
# )


# Copy Qt dll by windeployqt.cmake
# https://stackoverflow.com/questions/60854495/qt5-cmake-include-all-libraries-into-executable/60856725#60856725
if(WIN32)
  add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${QTDIR}/bin/windeployqt.exe $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
  )
endif()
