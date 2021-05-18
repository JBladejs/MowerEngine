cmake_minimum_required(VERSION 3.17)
project(MowerEngine)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
find_package(DevIL REQUIRED)
file(GLOB SOURCE "src/*.cpp" "src/*/*.cpp" "src/*/*/*.cpp")
#TODO: make it so the files are copied on assets change
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(MowerEngine ${SOURCE} src/Object2D.cpp src/Object2D.h src/graphics/Rectangle.cpp src/graphics/Rectangle.h src/graphics/texturing/Texture.cpp src/graphics/texturing/Texture.h src/graphics/texturing/TextureManager.cpp src/graphics/texturing/TextureManager.h src/graphics/animation/Animation.cpp src/graphics/animation/Animation.h)

#TODO: make it more platform independent
IF (WIN32)
    target_link_libraries(MowerEngine mingw32 SDL2::SDL2main SDL2::SDL2 opengl32 glu32 ${IL_LIBRARIES} ${ILU_LIBRARIES} -mconsole -mwindows)
ELSE()
    target_link_libraries(MowerEngine SDL2::SDL2main SDL2::SDL2 GL GLU ${IL_LIBRARIES} ${ILU_LIBRARIES})
ENDIF()

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${IL_INCLUDE_DIR}
)