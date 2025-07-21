//
// Created by ngixx on 07.07.2025.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <deque>
#include <map>
#include <memory>

#include "GameObject.h"
#include "../utils/Position2D.h"
#include "../utils/GameController.h"

class Snake : public GameObject {

    const char snakeSymbol = 'O';
    const char tailSymbol = 'o';

    const std::map<InputType, Position2D> velocityMap = {
        {UP, {0, -1}}, {DOWN, {0, 1}},
        {LEFT, {-1, 0}}, {RIGHT, {1, 0}}
    };
    Position2D velocity;
    std::vector<Position2D> body;
    bool isGrow = false;
public:
    Snake(char symbol, const Position2D &position, const Position2D &velocity);
    void update() override;
    void setVelocityByInput(InputType input);
    [[nodiscard]] Position2D getVelocity() const;
    [[nodiscard]] Position2D getHeadPosition() const;
    void setHeadPosition(const Position2D &position);
    [[nodiscard]] std::vector<RenderInfo> getRenderInfo() const override;
    void grow();
};

#endif //SNAKE_H
