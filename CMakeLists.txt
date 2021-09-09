cmake_minimum_required(VERSION 3.17)
project(MowerEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file(GLOB HEADER_FILES "src/*.h" "src/*/*.h" "src/*/*/*.h" "src/*/*/*/*.h" "src/*/*/*/*/*.h")
file(GLOB SOURCE_FILES "src/*.cpp" "src/*/*.cpp" "src/*/*/*.cpp" "src/*/*/*/*.cpp" "src/*/*/*/*/*.cpp")

message("Checking OpenGL...")
find_package(OpenGL REQUIRED)

message("Checking SDL2...")
find_package(SDL2 REQUIRED)

message("Checking DevIL...")
find_package(DevIL REQUIRED)

set(SOURCES
        ${SOURCE_FILES}
)

set(INCLUDES
        ${HEADER_FILES}
        ${SDL2_INCLUDE_DIR}
        ${IL_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
)

set(LIBS
        ${SDL2_LIBRARY}
        ${OPENGL_LIBRARIES}
        ${IL_LIBRARIES}
        ${ILU_LIBRARIES}
)

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})

IF(WIN32)
    message("Setting windows definitions...")
    add_definitions("-mconsole -mwindows")
ENDIF()

include_directories(${INCLUDES})
target_link_libraries(${PROJECT_NAME} ${LIBS})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})