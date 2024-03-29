####################################################################################################
# Project setting
####################################################################################################
cmake_minimum_required(VERSION 3.22.1)

project(EnglishAssistant)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")
if(WIN32)
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" ${CMAKE_FIND_LIBRARY_SUFFIXES})
    set(Qt5_DIR "C:/msys64/ucrt64/qt5-static/lib/cmake/Qt5")
endif()

####################################################################################################
# Find package
####################################################################################################
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
        Gui
        Widgets
        Network
        LinguistTools
)

####################################################################################################
# Build setting
####################################################################################################
# Add executable
add_executable(${CMAKE_PROJECT_NAME})

if(WIN32)
    if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
        set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE true)
    endif()
    
    # add app icon
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/resource.o
        COMMAND windres resource.rc -o ${CMAKE_CURRENT_BINARY_DIR}/resource.o
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/resource.rc
    )
    
    target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/resource.o)
endif()

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
    PRIVATE ${CMAKE_SOURCE_DIR}/src/english_assistance/config.cpp
    PRIVATE ${CMAKE_SOURCE_DIR}/src/english_assistance/crawler.cpp
    PRIVATE ${CMAKE_SOURCE_DIR}/src/english_assistance/main.cpp
    PRIVATE ${CMAKE_SOURCE_DIR}/src/english_assistance/translate.cpp
    PRIVATE ${CMAKE_SOURCE_DIR}/src/english_assistance/question.cpp
    PRIVATE ${CMAKE_SOURCE_DIR}/src/english_assistance/ui/main_window.cpp
    PRIVATE ${CMAKE_SOURCE_DIR}/src/english_assistance/util.cpp
)

#
# Link libraries
#
target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    PRIVATE Qt5::Gui
    PRIVATE Qt5::Widgets
    PRIVATE Qt5::Network
    PRIVATE Qt5::Core
    PRIVATE ${JNI_LIBRARIES}
)

####################################################################################################
# Copy files
####################################################################################################
# Copy crawler to build directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/lib/crawler/Crawler.class ${CMAKE_BINARY_DIR}/lib/crawler/Crawler.class
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/lib/crawler/lib ${CMAKE_BINARY_DIR}/lib/crawler/lib
)

# Copy assets to build directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets/images ${CMAKE_BINARY_DIR}/assets/images
)

# Copy assets to build directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/config ${CMAKE_BINARY_DIR}/config
)
