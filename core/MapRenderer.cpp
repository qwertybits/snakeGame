//
// Created by ngixx on 07.07.2025.
//

#include "MapRenderer.h"

#include <iostream>

MapRenderer::MapRenderer(const int width, const int height, const char wallChar) {
    defaultDrawMap(width + 2, height + 2, wallChar); // фізична мапа на 2 клітинки більший ніж ігрове поле
}

void MapRenderer::render(const std::vector<std::shared_ptr<GameObject>>& objects) const {
    system("cls");
    std::vector<std::string> output = map;
    for (const auto& object : objects) {
        auto renderPos = object->getPosition() + Position2D(1,1);
        output[renderPos.getY()][renderPos.getX()] = object->getSymbol();
    }
    for (const auto& renderLine : output) {
        std::cout << renderLine << std::endl;
    }
}

void MapRenderer::defaultDrawMap(int width, int height, char wallChar) {
    for (int i = 0; i < height; i++) {
        if (i == 0 || i == height - 1) {
            std::string line(width, wallChar);
            map.push_back(line);
        } else {
            std::string line(width, ' ');
            line[0] = wallChar;
            line[width-1] = wallChar;
            map.push_back(line);
        }
    }
}

