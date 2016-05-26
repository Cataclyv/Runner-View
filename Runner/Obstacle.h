#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include "Balle.h"

class Obstacle : public MovableElement
{
private:
    std::string _type;
public:
    Obstacle(int x, int y, int h, int w, int dx, int dy, std::string type);
    std::string getType() const;
};

#endif // OBSTACLE_H
