cmake_minimum_required(VERSION 3.17)
project(MowerEngine)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE "src/*.cpp" "src/*/*.cpp" "src/*/*/*.cpp")

add_executable(MowerEngine ${SOURCE})
target_link_libraries(MowerEngine -lmingw32 -lSDL2main -lSDL2 -lopengl32 -lglu32 -mconsole -mwindows)