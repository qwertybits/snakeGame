#include <iostream>

#include "core/GameField.h"

int main() {
    GameField gameField(18, 10, '#',
        Snake {'o', {0,0}, {0,0}});
    gameField.updateField();
    return 0;
}
