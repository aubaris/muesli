cmake_minimum_required(VERSION 3.16)

project(muesli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(MySourcesList 
    src/main.cpp    
)

set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/${CMAKE_SYSTEM_NAME}/include")
set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/${CMAKE_SYSTEM_NAME}/lib")
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/${CMAKE_SYSTEM_NAME}/lib/cmake/SFML")

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

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Building in Debug mode")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Building in Release mode")
else()
    message("No build mode set")
endif()

# message("Current CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
message("Generating for platform ${CMAKE_SYSTEM_NAME}")