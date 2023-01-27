
cmake_minimum_required(VERSION 3.14)

if (WIN32)
    project(tetris LANGUAGES CXX)
elseif(UNIX)
    project(tetris)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)

#=================== INCLUSION OF Project Files ====================#
set(SOURCES
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
============ SETUP EXECTUABLE ====================#
# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)



# Add the executable
if (WIN32) 
    add_executable(tetris WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(tetris ${SOURCES})
endif()


#===================== LINKING LIBRARIES =======================#
target_link_libraries(tetris Qt6::Widgets)

add_subdirectory(Test)
