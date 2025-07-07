//
// Created by ngixx on 07.07.2025.
//

#ifndef SNAKE_H
#define SNAKE_H
#include "GameObject.h"
#include "../utils/Position2D.h"

class Snake : public GameObject {
    Position2D velocity;
public:
    Snake(char symbol, const Position2D &position, const Position2D &velocity);
    void update() override;
};

#endif //SNAKE_H
