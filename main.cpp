#include <chrono>
#include <iostream>
#include <thread>

#include "core/GameField.h"

int main() {
    GameController controller;
    GameField gameField(18, 10, '#',
        Snake {'O', {0,0}, {1,0}});
    while (!gameField.isGameOver()) {
        try {
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
            gameField.updateField();
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
