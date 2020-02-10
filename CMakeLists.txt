cmake_minimum_required(VERSION 3.16)

project(muesli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(MySourcesList 
    src/main.cpp    
)

add_executable(muesli ${MySourcesList})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Building in Debug mode")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Building in Release mode")
else()
    message("No build mode set")
endif()

message("Current CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")