cmake_minimum_required(VERSION 3.17)
project(MowerEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file(GLOB HEADER_FILES "src/*.h" "src/*/*.h" "src/*/*/*.h" "src/*/*/*/*.h" "src/*/*/*/*/*.h")
file(GLOB SOURCE_FILES "src/*.cpp" "src/*/*.cpp" "src/*/*/*.cpp" "src/*/*/*/*.cpp" "src/*/*/*/*/*.cpp")

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(DevIL REQUIRED)
#find_package(Lua REQUIRED)

set(SOURCES ${SOURCE_FILES})
set(INCLUDES ${HEADER_FILES})
add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})

IF(WIN32)
    add_definitions("-mconsole -mwindows")
ENDIF()

include_directories(
        /usr/local/include
        ${SDL2_INCLUDE_DIR}
        ${IL_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${OPENGL_LIBRARIES} ${IL_LIBRARIES} ${ILU_LIBRARIES})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
