//
// Created by ngixx on 07.07.2025.
//

#include "Snake.h"

#include <iostream>

Snake::Snake(char symbol, const Position2D& position, const Position2D& velocity)
    : GameObject(symbol, position), velocity(velocity)
{
    body.push_back(position);
}

void Snake::update() {
    setPosition(getPosition() + velocity);
    body.front() = getPosition();

}

void Snake::setVelocityByInput(InputType input) {
    if (velocityMap.contains(input))
        velocity = velocityMap.at(input);
}

Position2D Snake::getVelocity() const {
    return velocity;
}

std::vector<Position2D> Snake::getRenderPositions() const {
    return body;
}

void Snake::grow() {
    body.push_back(body.back() - velocity);
}