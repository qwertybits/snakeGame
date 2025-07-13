//
// Created by ngixx on 07.07.2025.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <map>
#include <memory>

#include "GameObject.h"
#include "../utils/Position2D.h"
#include "../utils/GameController.h"

class Snake : public GameObject {
    const std::map<InputType, Position2D> velocityMap = {
        {UP, {0, -1}}, {DOWN, {0, 1}},
        {LEFT, {-1, 0}}, {RIGHT, {1, 0}}
    };
    Position2D velocity;
    GameController controller;
public:
    Snake(char symbol, const Position2D &position, const Position2D &velocity);
    void update() override;
};

#endif //SNAKE_H
