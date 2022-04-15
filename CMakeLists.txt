cmake_minimum_required(VERSION 3.21)
project(Chess)

set(CMAKE_CXX_STANDARD 14)
add_executable(Chess main.cpp MoveCalculator.cpp MoveCalculator.h Board.cpp Board.h Game.cpp Game.h Engine.cpp Engine.h MoveRecorder.cpp MoveRecorder.h)
