cmake_minimum_required(VERSION 3.28)
project(Car)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

find_package(CGAL REQUIRED COMPONENTS Core)

include(${CGAL_USE_FILE})

add_executable(Car
        main.cpp
        linear_algebra.h
        cube.hpp
        cube.cpp
)

target_link_libraries(Car
        sfml-graphics
        sfml-window
        sfml-system
)

target_link_libraries(Car
        ${CGAL_LIBRARIES}
        ${CGAL_3RD_PARTY_LIBRARIES}
)
