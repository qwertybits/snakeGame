//
// Created by ngixx on 07.07.2025.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

class GameController {
public:
    Direction getInputDirection(); // зчитує нажаті кнопки і повертає direction.
};

#endif //GAMECONTROLLER_H
