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
    Position2D previousPosition = getPosition();
    if (this->isGrow) {
        body.push_back(body.back());
        this->isGrow = false;
    }
    for (int i = 1; i < body.size(); i++) {
        const Position2D tmp = body[i];
        body[i] = previousPosition;
        previousPosition = tmp;
    }
    setPosition(getPosition() + velocity);
    body.front() = getPosition();
}

void Snake::setVelocityByInput(InputType input) {
    if (velocityMap.contains(input) && velocityMap.at(input) != Position2D::inverted(velocity))
        velocity = velocityMap.at(input);
}

Position2D Snake::getVelocity() const {
    return velocity;
}

std::vector<Position2D> Snake::getRenderPositions() const {
    return body;
}

void Snake::grow() {
    this->isGrow = true;
}