

cmake_minimum_required(VERSION 3.16)

project(tetris VERSION 1.0.0 LANGUAGES CXX)
enable_testing()
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        tetris.cpp
        tetris.h
        tetrisbox.cpp
        tetrisbox.h
        nexttetrisbox.cpp
        nexttetrisbox.h
        resource.qrc
)


qt_add_executable(tetris MANUAL_FINALIZATION ${PROJECT_SOURCES})
target_link_libraries(tetris PRIVATE Qt6::Widgets)

set_target_properties(tetris PROPERTIES

    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS tetris
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(tetris)
endif()



add_subdirectory(Test)
