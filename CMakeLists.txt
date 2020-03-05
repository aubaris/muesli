cmake_minimum_required(VERSION 3.13)

project(muesli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(MySourcesList 
    src/main.cpp
    src/ecs/ComponentManager.cpp
    src/ecs/Components.cpp
    src/ecs/Engine.cpp
    src/ecs/RenderSystem.cpp
    src/ecs/ColorChangeSystem.cpp
    src/ecs/DebuggingSystem.cpp
    src/ecs/Entity.cpp
    src/ecs/EntityDefinitions.cpp
    src/App.cpp
)

find_package( Threads )

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message("Generating for os \"${CMAKE_SYSTEM_NAME}\"")
set(VS_VERSION "")

# Differentiate between visual studio versions
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	if(${MSVC_VERSION} GREATER_EQUAL 1910 AND ${MSVC_VERSION} LESS_EQUAL 1919)
		message("Building for VS 15")
		# set(VS_VERSION "")
	elseif(${MSVC_VERSION} GREATER_EQUAL 1920 AND ${MSVC_VERSION} LESS_EQUAL 1929)
		message("Building for VS 16")
		set(VS_VERSION "VS16_x64/")
	else()
		message(FATAL_ERROR "Not configured for MSVC_VERSION ${MSVC_VERSION}")
	endif()
endif()

include_directories("include")

set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/${CMAKE_SYSTEM_NAME}/${VS_VERSION}include")
set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/${CMAKE_SYSTEM_NAME}/${VS_VERSION}lib")
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/${CMAKE_SYSTEM_NAME}/${VS_VERSION}lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
else()
    message(FATAL_ERROR "SFML NOT FOUND")
endif()

add_executable(muesli ${MySourcesList})
target_link_libraries(muesli sfml-graphics sfml-audio)
target_link_libraries( muesli ${CMAKE_THREAD_LIBS_INIT} )

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Building in Debug mode")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Building in Release mode")
else()
    message("No build mode set")
endif()

# message("Current CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
message("Generating for platform ${CMAKE_SYSTEM_NAME}")