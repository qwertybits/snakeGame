//
// Created by ngixx on 06.07.2025.
//

#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include <memory>

#include "MapRenderer.h"
#include "../objects/GameObject.h"
#include "../objects/Snake.h"


//Клас GameField відповідає за керування ігровим процесом і взаємодією ігрових об'єктів
class GameField {
    std::vector<std::shared_ptr<GameObject>> gameObjects; // список ігрових об'єктів (для рендерингу)
    MapRenderer mapRenderer; // Об'єкт ігрової мапи (поля), відповідає за рендеринг в консоль
    std::shared_ptr<Snake> snake; // Об'єкт змійки
    GameController controller; // Об'єкт ігрового контролера (відповідає за userinput)
    bool gameOver;  // Флаг що відповідає за кінець гри

    int width, height; //Висота і ширина ігрового поля
    [[nodiscard]] bool checkSnakeCollision() const; // Перевіряє всі випадки колізії змійки
public:
    GameField(int width, int height, char wallChar, Snake&& snake);
    bool updateField(); // Відповідає за оновлення ігрового поля і всіх об'єктів та рендеринг
    [[nodiscard]] std::shared_ptr<Snake> getSnake() const;
    [[nodiscard]] bool isGameOver() const;
};

#endif //GAMEFIELD_H
