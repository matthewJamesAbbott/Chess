cmake_minimum_required(VERSION 3.00)
project(Chess)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

set(CMAKE_CXX_STANDARD 14)
add_executable(Chess main.cpp MoveCalculator.cpp MoveCalculator.h Board.cpp Board.h Game.cpp Game.h Engine.cpp Engine.h MoveRecorder.cpp MoveRecorder.h)

target_include_directories(${PROJECT_NAME} PRIVATE
         include ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})


target_link_libraries(Chess stdc++fs ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES} SDL2)
