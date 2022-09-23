cmake_minimum_required(VERSION 3.16.3)
project(3D_Renderer_from_scratch)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers source)

find_package(SFML REQUIRED system graphics window audio)

set(SOURCES
        Main.cpp
        source/Application.cpp
        source/Box.cpp
        source/Camera.cpp
        source/FileReader.cpp
        source/KeyboardHandler.cpp
        source/Sphere.cpp
        source/Triangle.cpp
        source/Window.cpp
        source/World.cpp
        )

set(HEADERS
        headers/Application.hpp
        headers/Box.hpp
        headers/Camera.hpp
        headers/FileReader.hpp
        headers/KeyboardHandler.hpp
        headers/Sphere.hpp
        headers/Triangle.hpp
        headers/Window.hpp
        headers/World.hpp
        )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} -lsfml-graphics -lsfml-window -lsfml-system)


