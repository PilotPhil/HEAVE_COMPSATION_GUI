cmake_minimum_required(VERSION 3.5)

project(HEAVE_COMPENSATION VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets SerialPort PrintSupport REQUIRED)

SET(QCustomPlot_Include_Dir D:/ProgramFiles/Develop/QCustomPlot)
SET(QCustomPlot_SOURCE D:/ProgramFiles/Develop/QCustomPlot/qcustomplot.cpp)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source/ui
                    ${CMAKE_CURRENT_LIST_DIR}/source/imu
                    ${CMAKE_CURRENT_LIST_DIR}/source/plot
                    ${CMAKE_CURRENT_LIST_DIR}/source/pid
                    ${CMAKE_CURRENT_LIST_DIR}/source/cfg
                    ${CMAKE_CURRENT_LIST_DIR}/source/motor
                    ${CMAKE_CURRENT_LIST_DIR}/source/plot/base
                    ${CMAKE_CURRENT_LIST_DIR}/source/plot/staticPlot
                    ${CMAKE_CURRENT_LIST_DIR}/source/plot/dynamicPlot
                    ${CMAKE_CURRENT_LIST_DIR}/source/plot/dialog
                    ${CMAKE_CURRENT_LIST_DIR}/source/plot/prop
                    ${QCustomPlot_Include_Dir})

file(GLOB_RECURSE PROJECT_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/source/*.*
    ${QCustomPlot_SOURCE})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(HEAVE_COMPENSATION
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET HEAVE_COMPENSATION APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(HEAVE_COMPENSATION SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(HEAVE_COMPENSATION
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(HEAVE_COMPENSATION PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                                 Qt${QT_VERSION_MAJOR}::SerialPort
                                                 Qt${QT_VERSION_MAJOR}::PrintSupport)

set_target_properties(HEAVE_COMPENSATION PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(HEAVE_COMPENSATION)
endif()
