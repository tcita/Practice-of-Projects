####################################################################################################
# Project setting
####################################################################################################
# Set cmake standard
cmake_minimum_required(VERSION 3.22.1)

# Set c++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
if(WIN32)
    set(Qt6_DIR "C:/msys64/ucrt64/qt6-static/lib/cmake/Qt6")
endif()

# Set project information
project(EnglishAssistant)

####################################################################################################
# Find package
####################################################################################################
# Add subdirectory nlohmann_json
# From: https://github.com/nlohmann/json
find_package(nlohmann_json REQUIRED)

# Find JNI package
# ``JNI_INCLUDE_DIRS``
#   the include dirs to use
# ``JNI_LIBRARIES``
#   the libraries to use (JAWT and JVM)
# ``JNI_FOUND``
#   TRUE if JNI headers and libraries were found.
find_package(JNI REQUIRED)

# Find Qt package
find_package(
    Qt5 REQUIRED
    COMPONENTS
        Core
        Widgets
        Network
        LinguistTools
)

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
    PRIVATE ${CMAKE_SOURCE_DIR}/src/Question.cpp
    PRIVATE ${CMAKE_SOURCE_DIR}/src/Strings.cpp
    PRIVATE ${CMAKE_SOURCE_DIR}/src/Questions.cpp
    PRIVATE ${CMAKE_SOURCE_DIR}/src/Config.cpp
)

#
# Link libraries
#
target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    PRIVATE nlohmann_json
    PRIVATE Qt5::Core
    PRIVATE Qt5::Gui
    PRIVATE Qt5::Widgets
    PRIVATE Qt5::Network
    PRIVATE ${JNI_LIBRARIES}
)

####################################################################################################
# Copy files
####################################################################################################
# Copy crawler to build directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/lib/crawler/Scraper.class ${CMAKE_BINARY_DIR}/lib/crawler/Scraper.class
)

# Copy assets to build directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets/image ${CMAKE_BINARY_DIR}/assets/image
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/lib/jsoup ${CMAKE_BINARY_DIR}/lib/jsoup
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/config ${CMAKE_BINARY_DIR}/config
)
