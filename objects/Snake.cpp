//
// Created by ngixx on 07.07.2025.
//

#include "Snake.h"

Snake::Snake(char symbol, const Position2D& position, const Position2D& velocity)
            : GameObject(symbol, position), velocity(velocity) {}

void Snake::update() {
    setPosition(getPosition() + velocity);
}
