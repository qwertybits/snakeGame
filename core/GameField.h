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
public:
    GameField(int width, int height, char wallChar, Snake&& snake);
    void updateField() const;
    [[nodiscard]] std::shared_ptr<Snake> getSnake() const;
};

#endif //GAMEFIELD_H
