//
// Created by ngixx on 07.07.2025.
//

#ifndef MAPRENDERER_H
#define MAPRENDERER_H
#include <list>
#include <memory>
#include <string>
#include <vector>

#include "../objects/GameObject.h"

class MapRenderer {
    std::vector<std::string> map;
public:
    MapRenderer(int width, int height, char wallChar);
    void render(const std::vector<std::shared_ptr<GameObject>>& objects) const;
private:
    void defaultDrawMap(int width, int height, char wallChar);
};

#endif //MAPRENDERER_H
