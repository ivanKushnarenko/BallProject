cmake_minimum_required(VERSION 3.15)
project(Ball)

set(CMAKE_CXX_STANDARD 17)

#add_executable(Artem client.cpp Shapes.cpp Shapes.h)
add_executable(BallTest ball.cpp Shapes.cpp Shapes.h)


set(SFML_INCLUDE_DIR "C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit/SFML-2.5.1/lib")
set(SFML_DIR "C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

#target_link_libraries (Ball sfml-graphics sfml-window sfml-system sfml-network)
target_link_libraries(BallTest sfml-graphics sfml-window sfml-system)
