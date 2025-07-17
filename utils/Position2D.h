//
// Created by ngixx on 06.07.2025.
//

#ifndef POSITION2D_H
#define POSITION2D_H
#include <stdexcept>


//Вспоміжний клас для реалізації системи координат
class Position2D {
    int x {}, y {};
public:
    Position2D(int x, int y) : x(x), y(y) {}
    [[nodiscard]] int getX() const { return x; }
    [[nodiscard]] int getY() const { return y; }
    void setX(const int x) {
        if (x<0)
            throw std::out_of_range("Position2D::setX out of range");
        this->x = x;
    }
    void setY(const int y) {
        if (y<0)
            throw std::out_of_range("Position2D::setY out of range");
        this->y = y;
    }

    Position2D operator+(const Position2D &other) const {
        return {x+other.x, y+other.y};
    }

    Position2D operator-(const Position2D &other) const {
        return {x-other.x, y-other.y};
    }

    Position2D& operator++() {
        x++;
        y++;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &os, const Position2D &pos) {
        return os << "( " << pos.x << ", " << pos.y << " )";
    }
};

#endif //POSITION2D_H
