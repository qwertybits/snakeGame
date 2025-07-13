//
// Created by ngixx on 07.07.2025.
//

#include "Snake.h"

Snake::Snake(char symbol, const Position2D& position, const Position2D& velocity)
    : GameObject(symbol, position), velocity(velocity)
{}

void Snake::update() {
    auto input = controller.getInput();
    if (input == EXIT) {
        throw std::runtime_error("game over");
    }
    if (input != NONE) {
        velocity = velocityMap.at(input);
    }
    setPosition(getPosition() + velocity);
}
