//
// Created by ngixx on 06.07.2025.
//

#include "GameField.h"

#include <iostream>


bool GameField::checkSnakeCollision() const {
    const auto nextPos = snake->getPosition() + snake->getVelocity();
    if (nextPos.getX() >= width || nextPos.getY() >= height || nextPos.getX() < 0 || nextPos.getY() < 0) {
        return true;
    }
    return false;
}

GameField::GameField(int width, int height, char wallChar, Snake&& snake)
    : mapRenderer(width, height, wallChar)
{
    this->width = width;
    this->height = height;
    this->gameOver = false;
    this->snake = std::make_shared<Snake>(std::move(snake));

    gameObjects.push_back(this->snake);

    mapRenderer.render(gameObjects);
}

bool GameField::updateField() {
    if (checkSnakeCollision()) {
        gameOver = true;
        return false;
    }
    auto userInput = controller.getInput();
    if (userInput == EXIT) {
        gameOver = true;
        return false;
    }
    snake->setVelocityByInput(userInput);
    snake->update();
    mapRenderer.render(gameObjects);
    std::cout << snake->getPosition() << std::endl;

    return true;
}

std::shared_ptr<Snake> GameField::getSnake() const {
    return this->snake;
}

bool GameField::isGameOver() const {
    return gameOver;
}


