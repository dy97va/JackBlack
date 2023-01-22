cmake_minimum_required(VERSION 3.23)
project(JackBlack)

set(CMAKE_CXX_STANDARD 20)

add_executable(JackBlack main.cpp Card.cpp Card.h Game.cpp Game.h Player.cpp Player.h Strategy.cpp Strategy.h)
