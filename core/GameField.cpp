//
// Created by ngixx on 06.07.2025.
//

#include "GameField.h"

GameField::GameField(int width, int height, char wallChar, Snake&& snake)
    : mapRenderer(width, height, wallChar)
{
    this->snake = std::make_shared<Snake>(std::move(snake));
    gameObjects.push_back(this->snake);
    mapRenderer.render(gameObjects);
}

void GameField::updateField() const {
    for (const auto& gameObject : gameObjects) {
        gameObject->update();
    }
    mapRenderer.render(gameObjects);
}

std::shared_ptr<Snake> GameField::getSnake() const {
    return this->snake;
}


