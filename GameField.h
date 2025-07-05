//
// Created by ngixx on 05.07.2025.
//

#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <vector>
#include <string>
#include "Position2D.h"

class GameField {
    std::vector<std::string> map;
    int width = {}, height = {};
    char borderWall;
public:
    explicit GameField(int width, int height, char wallChar) {
        this->width = width;
        this->height = height;
        this->borderWall = wallChar;
        initMap();
    }

    [[nodiscard]] std::vector<std::string> getMap() const {
        return map;
    }

    void putObject(char ch, Position2D startPos) {
        map[startPos.getY() + 1][startPos.getX() + 1] = ch;
    }

private:
    void initMap() {
        for (int i = 0; i < height; i++) {
            if (i == 0 || i == height - 1) {
                std::string line(width, borderWall);
                map.push_back(line);
            } else {
                std::string line(width, ' ');
                line[0] = borderWall;
                line[width - 1] = borderWall;
                map.push_back(line);
            }
        }
    }
};



#endif //GAMEFIELD_H
