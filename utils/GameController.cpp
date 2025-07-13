//
// Created by ngixx on 07.07.2025.
//

#include "GameController.h"

#include <conio.h>

InputType GameController::getInput() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w':
                return UP;
            case 's':
                return DOWN;
            case 'a':
                return LEFT;
            case 'd':
                return RIGHT;
            case 'q':
                return EXIT;
            default:
                return NONE;
        }
    }
    return NONE;
}
