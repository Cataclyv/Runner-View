#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include "Balle.h"

class Obstacle : public MovableElement
{
private:
    int _dommages;
public:
    Obstacle(int x, int y, int h, int w, int dx, int dy);
    std::string getType() const;
};

#endif // OBSTACLE_H
