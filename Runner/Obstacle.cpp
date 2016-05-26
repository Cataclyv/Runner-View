#include "Obstacle.h"

using namespace std;

Obstacle::Obstacle(int x, int y, int h, int w, int dx, int dy, std::string type):
    MovableElement{x, y, h, w, dx, dy}, _type{type}
{}

string Obstacle::getType() const {
    return _type;
}

void Obstacle::verbose() const
{
    cout << "\"" << _type << "\" créé aux coordonnées (" << _x << ", " << _y << ")" << endl;
}
