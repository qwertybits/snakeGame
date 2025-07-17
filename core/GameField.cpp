//
// Created by ngixx on 06.07.2025.
//

#include "GameField.h"

#include <iostream>


bool GameField::checkSnakeCollision() const {
    const auto nextPos = snake->getPosition() + snake->getVelocity(); //заглядаємо в наступну позиції змійки
    if (nextPos.getX() >= width || nextPos.getY() >= height || nextPos.getX() < 0 || nextPos.getY() < 0) {
        //якщо наступна позиція виходить за межі ігрового поля - значить це колізія
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
    auto userInput = controller.getInput(); // Отримуємо ввід користувача
    if (userInput == EXIT) { // Якщо вихід - закінчуємо гру
        gameOver = true;
        return false;
    }
    snake->setVelocityByInput(userInput); // Оновлюємо напрямок(швидкість) руху змійки на основі userinput'а
    if (checkSnakeCollision()) { // Перевіряємо чи наступний крок змійки - це не колізія
        gameOver = true; //якщо так - викидаємо з гри
        return false;
    }
    snake->update(); // Оновлюємо стан змійки якщо все ОК
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


