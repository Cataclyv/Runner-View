#include "Bonus.h"

using namespace std;

Bonus::Bonus(int x, int taille, int vitesse, string type) :
    MovableElement(x, 300, taille, taille, -vitesse, 0), _type{type}
{}

void Bonus::move() {
    _x += _dx;
}

string Bonus::getType() const {
    return _type;
}

void Bonus::verbose() const
{
    cout << "\"" << _type << "\" créé aux coordonnées (" << _x << ", " << _y << ")" << endl;
}
