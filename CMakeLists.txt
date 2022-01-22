cmake_minimum_required(VERSION 3.17)
project(MowerEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(AS_LIBRARY OFF)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB HEADER_FILES "src/*.h" "src/*/*.h" "src/*/*/*.h" "src/*/*/*/*.h" "src/*/*/*/*/*.h")
file(GLOB SOURCE_FILES "src/*.cpp" "src/*/*.cpp" "src/*/*/*.cpp" "src/*/*/*/*.cpp" "src/*/*/*/*/*.cpp")

message("Checking OpenGL...")
find_package(OpenGL REQUIRED)

message("Checking SDL2...")
find_package(SDL2 REQUIRED)

message("Checking DevIL...")
find_package(DevIL REQUIRED)

message("Checking Lua...")
find_package(Lua REQUIRED)
add_definitions("-llua")

message("Checking SOL2...")
find_package(SOL2 REQUIRED)

set(SOURCES ${SOURCE_FILES} src/logic/components/Script.h src/scripting/LuaEntity.cpp src/scripting/LuaCoordinator.cpp src/scripting/LuaSystem.cpp src/scripting/LuaCollider.cpp src/scripting/LuaPosition.cpp src/scripting/LuaCollision.cpp src/scripting/LuaTextured.cpp src/scripting/LuaCollisionSystem.cpp src/scripting/LuaTexturingSystem.cpp)

set(INCLUDES
        ${SDL2_INCLUDE_DIR}
        ${IL_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
        ${LUA_INCLUDE_DIR}
        ${SOL2_INCLUDE_DIR}
        )

set(LIBS
        ${SDL2_LIBRARY}
        ${OPENGL_LIBRARIES}
        ${IL_LIBRARIES}
        ${ILU_LIBRARIES}
        ${LUA_LIBRARIES}
        )

message(${CMAKE_BUILD_TYPE})
IF(CMAKE_BUILD_TYPE MATCHES Debug)
    set(TERM_LOGS ON)
    message("Messages will be printed instead of logged.")
ELSE()
    set(TERM_LOGS OFF)
    message("Messages will be logged.")
ENDIF()

include_directories(${INCLUDES})

IF(AS_LIBRARY)
    add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADER_FILES})
ELSE()
    add_executable(${PROJECT_NAME} ${SOURCES} ${HEADER_FILES})
ENDIF()

IF(WIN32)
    add_definitions("-mconsole -mwindows")
ENDIF()

IF(TERM_LOGS)
    add_definitions(-DTERM_LOGS)
ENDIF()
target_link_libraries(${PROJECT_NAME} ${LIBS})