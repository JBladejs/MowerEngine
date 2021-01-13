cmake_minimum_required(VERSION 3.17)
project(MowerEngine)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
file(GLOB SOURCE "src/*.cpp" "src/*/*.cpp" "src/*/*/*.cpp")

add_executable(MowerEngine ${SOURCE})

IF (WIN32)
    target_link_libraries(MowerEngine mingw32 SDL2::SDL2main SDL2::SDL2 opengl32 glu32 -mconsole -mwindows)
ELSE()
    target_link_libraries(MowerEngine SDL2::SDL2main SDL2::SDL2 GL GLU)
ENDIF()