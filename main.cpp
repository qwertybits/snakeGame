#include <chrono>
#include <thread>

#include "core/GameField.h"

[[noreturn]] int main() {
    GameController controller;
    GameField gameField(18, 10, '#',
        Snake {'O', {0,0}, {1,0}});
    std::this_thread::sleep_for(std::chrono::milliseconds(900));
    while (true) {
        gameField.updateField();
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}
