cmake_minimum_required(VERSION 3.9)
project(GameTest)

set(SOURCES include/Ghost.h include/Game.h include/Factory.h include/SDLFactory.h src/main.cpp src/Game.cpp src/SDL/SDLFactory.cpp src/Entities/SDLGhost.cpp src/Factory.cpp src/Entities/Ghost.cpp src/Event.cpp include/Event.h src/SDL/SDLEvent.cpp include/SDLEvent.h src/SDL/SDLContext.cpp include/SDLContext.h src/Entities/Entity.cpp include/Entity.h include/Factory.h src/Entities/MovingEntity.cpp include/MovingEntity.h include/Types.h src/Entities/PacMan.cpp include/PacMan.h src/Entities/SDLPacMan.cpp include/SDLPacMan.h include/SDLGhost.h src/Entities/Tile.cpp include/Tile.h src/Entities/SDLTile.cpp include/SDLTile.h src/Map.cpp include/Map.h src/SDL/SDLMap.cpp include/SDLMap.h src/AI.cpp include/AI.h src/GreedyAI.cpp include/GreedyAI.h src/UI/GameUI.cpp include/GameUI.h src/UI/View.cpp include/View.h src/UI/TextView.cpp include/TextView.h src/UI/SDLTextView.cpp include/SDLTextView.h src/Timing/Timer.cpp include/Timer.h src/Timing/SDLTimer.cpp include/SDLTimer.h)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

add_executable(GameTest ${SOURCES})

target_link_libraries(GameTest ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_LIBRARIES})