//
// Created by ngixx on 07.07.2025.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

//Види користувацького вводу
enum InputType {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    EXIT,
    NONE
};

class GameController {
public:
    InputType getInput(); // зчитує натиснуті кнопки та повертає InputType
};

#endif //GAMECONTROLLER_H
