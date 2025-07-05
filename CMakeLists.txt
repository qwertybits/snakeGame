cmake_minimum_required(VERSION 3.31)
project(snakeGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(snakeGame main.cpp
        GameField.cpp
        GameField.h
        Position2D.h
        GameObject.cpp
        GameObject.h)
