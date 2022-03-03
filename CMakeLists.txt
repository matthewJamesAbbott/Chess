cmake_minimum_required(VERSION 3.21)
project(Chess)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)
add_executable(Chess main.cpp MoveCalculator.cpp MoveCalculator.h Board.cpp Board.h Game.cpp Game.h NetClient.cpp NetClient.h NetServer.cpp NetServer.h)
