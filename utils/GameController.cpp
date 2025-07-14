//
// Created by ngixx on 07.07.2025.
//

#include "GameController.h"

#include <conio.h>

InputType GameController::getInput() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w': case 'W':
                return UP;
            case 's': case 'S':
                return DOWN;
            case 'a': case 'A':
                return LEFT;
            case 'd': case 'D':
                return RIGHT;
            case 'q' : case 'Q':
                return EXIT;
            default:
                return NONE;
        }
    }
    return NONE;
}
