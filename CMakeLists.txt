cmake_minimum_required(VERSION 3.16)

project(muesli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(MySourcesList 
    src/main.cpp    
)

add_executable(muesli ${MySourcesList})