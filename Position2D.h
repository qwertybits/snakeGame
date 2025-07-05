//
// Created by ngixx on 05.07.2025.
//

#ifndef POSITION2D_H
#define POSITION2D_H
#include <stdexcept>


class Position2D {
    int x = 0, y = 0;
public:
    Position2D(int x, int y) {
        setX(x);
        setY(y);
    }
    [[nodiscard]] int getX() const { return x; }
    [[nodiscard]] int getY() const { return y; }

    void setX(int x) {
        if (x < 0) throw std::out_of_range("Out of range: Position2D");
        this->x = x;
    }

    void setY(int y) {
        if (y < 0) throw std::out_of_range("Out of range: Position2D");
        this->y = y;
    }
};

#endif //POSITION2D_H
