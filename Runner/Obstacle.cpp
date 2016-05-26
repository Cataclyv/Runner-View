#include "Obstacle.h"

Obstacle::Obstacle(int x, int y, int h, int w, int dx, int dy, std::string type):
    MovableElement{x, y, h, w, dx, dy}, _type{type}
{}

std::string Obstacle::getType() const {
    return _type;
}
