cmake_minimum_required(VERSION 3.9)
project(GameTest)

set(SOURCES include/logic/Clyde.h include/logic/Inky.h include/logic/Pinky.h src/AI/Pinky.cpp src/AI/Inky.cpp src/AI/Clyde.cpp include/logic/Ghost.h include/logic/Game.h include/logic/Factory.h include/SDL/SDLFactory.h src/main.cpp src/Game.cpp src/SDL/SDLFactory.cpp src/Entities/SDLGhost.cpp src/Factory.cpp src/Entities/Ghost.cpp src/Event.cpp include/logic/Event.h src/SDL/SDLEvent.cpp include/SDL/SDLEvent.h src/SDL/SDLContext.cpp include/SDL/SDLContext.h src/Entities/Entity.cpp include/logic/Entity.h include/logic/Factory.h src/Entities/MovingEntity.cpp include/logic/MovingEntity.h include/Types.h src/Entities/PacMan.cpp include/logic/PacMan.h src/Entities/SDLPacMan.cpp include/SDL/SDLPacMan.h include/SDL/SDLGhost.h src/Entities/Tile.cpp include/logic/Tile.h src/Entities/SDLTile.cpp include/SDL/SDLTile.h src/Map.cpp include/logic/Map.h src/SDL/SDLMap.cpp include/SDL/SDLMap.h src/AI/AI.cpp include/logic/AI.h src/AI/Blinky.cpp include/logic/Blinky.h src/UI/GameUI.cpp include/logic/GameUI.h src/UI/View.cpp include/logic/View.h src/UI/TextView.cpp include/logic/TextView.h src/UI/SDLTextView.cpp include/SDL/SDLTextView.h src/Timing/Timer.cpp include/logic/Timer.h src/Timing/SDLTimer.cpp include/SDL/SDLTimer.h src/UI/Button.cpp include/logic/Button.h src/UI/SDLButton.cpp include/SDL/SDLButton.h)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

add_executable(GameTest ${SOURCES})

target_link_libraries(GameTest ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_LIBRARIES})