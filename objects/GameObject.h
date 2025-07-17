//
// Created by ngixx on 06.07.2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "../utils/Position2D.h"


//Інтерфейс для всіх ігрових об'єктів
class GameObject {
    char SYMBOL {};
    Position2D position;
public:
    [[nodiscard]] Position2D getPosition() const { return position; }
    void setPosition(const Position2D& position) { this->position = position; }
    [[nodiscard]] char getSymbol() const { return SYMBOL; }
    void setSymbol(char symbol) { this->SYMBOL = symbol; }
    virtual ~GameObject() = default;
    GameObject(const char SYM, const Position2D position) : SYMBOL{SYM}, position{position} {}
    virtual void update() = 0;
};

#endif //GAMEOBJECT_H
