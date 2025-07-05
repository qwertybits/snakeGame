#include <iostream>

#include "GameField.h"

constexpr char HEAD_CHAR = 'O';
constexpr char TAIL_CHAR = 'o';
constexpr char APPLE_CHAR = '*';
constexpr char WALL_CHAR = '#';


void printGameField(const GameField& gameField) {
    for (const auto &str: gameField.getMap()) {
        std::cout << str << std::endl;
    }
}


int main() {
    try {
        GameField field(18,10, WALL_CHAR);
        field.putObject(APPLE_CHAR, {0, 0});
        printGameField(field);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}