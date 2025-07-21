//
// Created by ngixx on 21.07.2025.
//

#ifndef RENDERINFO_H
#define RENDERINFO_H
#include <vector>

#include "Position2D.h"

class RenderInfo {
    std::pair<Position2D, char> renderData;
public:
    RenderInfo(Position2D pos, char ch): renderData(pos,ch) {}
    [[nodiscard]] Position2D renderPos() const {
        return renderData.first;
    }
    [[nodiscard]] char renderSym() const {
        return renderData.second;
    }
};

#endif //RENDERINFO_H
