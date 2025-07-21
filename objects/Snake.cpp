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
    Position2D previousPosition = getHeadPosition();
    if (this->isGrow) {
        body.push_back(body.back());
        this->isGrow = false;
    }
    for (int i = 1; i < body.size(); i++) {
        const Position2D tmp = body[i];
        body[i] = previousPosition;
        previousPosition = tmp;
    }
    setHeadPosition(getHeadPosition() + velocity);
}

std::vector<RenderInfo> Snake::getRenderInfo() const {
    std::vector<RenderInfo> result;
    result.emplace_back(getHeadPosition(), snakeSymbol);
    for (int i = 1; i < body.size(); i++) {
        result.emplace_back(body[i], tailSymbol);
    }
    return result;
}

void Snake::setVelocityByInput(InputType input) {
    if (velocityMap.contains(input) && velocityMap.at(input) != Position2D::inverted(velocity))
        velocity = velocityMap.at(input);
}

Position2D Snake::getVelocity() const {
    return velocity;
}

Position2D Snake::getHeadPosition() const {
    return body.front();
}

void Snake::setHeadPosition(const Position2D &position) {
    body.front() = position;
}

void Snake::grow() {
    this->isGrow = true;
}
