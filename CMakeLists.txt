cmake_minimum_required(VERSION 3.9)
project(GameTest)

set(SOURCES main.cpp Game.cpp SDLFactory.cpp SDLGhost.cpp Factory.cpp DirectXFactory.cpp Ghost.cpp DirectXGhost.cpp)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(GameTest ${SOURCES})

target_link_libraries(GameTest ${SDL2_IMAGE_LIBRARIES} ${SDL2_LIBRARIES})