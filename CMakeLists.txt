cmake_minimum_required(VERSION 3.31)
project(snakeGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(snakeGame main.cpp
        core/GameField.cpp
        core/GameField.h
        objects/GameObject.h
        utils/Position2D.h
        core/MapRenderer.cpp
        core/MapRenderer.h
        utils/GameController.cpp
        utils/GameController.h
        objects/Snake.cpp
        objects/Snake.h
        utils/RenderInfo.h
)
