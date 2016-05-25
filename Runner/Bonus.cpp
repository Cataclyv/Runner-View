#include "Bonus.h"

using namespace std;

Bonus::Bonus(int x, int vitesse, string type) :
    MovableElement(x, 300, 0, 0, vitesse, 0), _type{type}
{
    cout <<  _type << " créé aux coordonnées ("
          << _x << ", " << _y << ")" << endl;
}

void Bonus::move() {
    _x += _dx;
}

std::string Bonus::getType() const {
    return _type;
}
