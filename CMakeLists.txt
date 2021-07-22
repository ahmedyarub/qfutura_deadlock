cmake_minimum_required(VERSION 3.14)
project(qfutura_deadlock LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Concurrent)
find_package(Qt6 COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Network)

qt_add_executable(qfutura_deadlock
        download.cpp
        download.h
        main.cpp
        )
set_target_properties(qfutura_deadlock PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE TRUE
        )
target_link_libraries(qfutura_deadlock PUBLIC
        Qt::Concurrent
        Qt::Core
        Qt::Gui
        Qt::Network
        Qt::Widgets
        )