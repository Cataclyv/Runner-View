#include "Bonus.h"

Bonus::Bonus() : MovableElement(100,100,TAILLE,TAILLE,0,0), _valPoints(50)
{}

Bonus::Bonus(int x, int valeur) :
    MovableElement(x, 100, 0, 0, -1, 0), _valPoints(valeur)
{
    std::cout<< "Bonus créé aux coordonnées ("
             << _x << ", " << _y << ")";
}

void Bonus::move() {
    _x += _dx;
}

int Bonus::getVal() const
{
    std::cout << _valPoints << std::endl;
}

std::string Bonus::getType() const {
    return "Bonus";
}
