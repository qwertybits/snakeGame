//
// Created by ngixx on 06.07.2025.
//

#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include <memory>

#include "MapRenderer.h"
#include "../objects/GameObject.h"
#include "../objects/Snake.h"

class GameField {
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    MapRenderer mapRenderer;
    std::shared_ptr<Snake> snake;
    GameController controller;
    bool gameOver;

    int width, height;
    [[nodiscard]] bool checkSnakeCollision() const;
public:
    GameField(int width, int height, char wallChar, Snake&& snake);
    bool updateField();
    [[nodiscard]] std::shared_ptr<Snake> getSnake() const;
    [[nodiscard]] bool isGameOver() const;
};

#endif //GAMEFIELD_H
