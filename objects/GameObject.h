//
// Created by ngixx on 06.07.2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
#include <bits/locale_facets_nonio.h>

#include "../utils/Position2D.h"
#include "../utils/RenderInfo.h"


//Інтерфейс для всіх ігрових об'єктів
class GameObject {
    char SYMBOL {};
    Position2D position;
public:
    [[nodiscard]] virtual std::vector<RenderInfo> getRenderInfo() const {return {{position, SYMBOL}}; }
    void setPosition(const Position2D& position) { this->position = position; }
    void setSymbol(char symbol) { this->SYMBOL = symbol; }
    virtual ~GameObject() = default;
    GameObject(const char SYM, const Position2D position) : SYMBOL{SYM}, position{position} {}
    virtual void update() = 0;
};

#endif //GAMEOBJECT_H
