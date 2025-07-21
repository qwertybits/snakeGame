#include <chrono>
#include <iostream>
#include <thread>

#include "core/GameField.h"

int main() {
    GameField gameField(18, 10, '#',
        Snake {'O', {0,0}, {1,0}});
    while (!gameField.isGameOver()) {
        try {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            gameField.updateField();
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    // gameField.getSnake()->grow();
    // gameField.getSnake()->update();
    // for (const auto& part : gameField.getSnake()->getRenderPositions()) {
    //     std::cout << part << " ";
    // }
    return 0;
}
