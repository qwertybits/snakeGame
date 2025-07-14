//
// Created by ngixx on 06.07.2025.
//

#include "GameField.h"

GameField::GameField(int width, int height, char wallChar, Snake&& snake)
    : mapRenderer(width, height, wallChar)
{
    gameOver = false;
    this->snake = std::make_shared<Snake>(std::move(snake));
    gameObjects.push_back(this->snake);
    mapRenderer.render(gameObjects);
}

bool GameField::updateField() {
    auto userInput = controller.getInput();
    if (userInput == EXIT)
        gameOver = true;
    else {
        snake->setVelocityByInput(userInput);
        snake->update();
        mapRenderer.render(gameObjects);
    }
    return true;
}

std::shared_ptr<Snake> GameField::getSnake() const {
    return this->snake;
}

bool GameField::isGameOver() const {
    return gameOver;
}


