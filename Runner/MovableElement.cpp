#include "MovableElement.h"

int MovableElement::_nbME = 0;

MovableElement::MovableElement(int x, int y, int w, int h, int dx, int dy)
    : _id{_nbME++}, _x{x}, _y{y}, _w{w}, _h{h}, _dx{dx}, _dy{dy}
{
}

MovableElement::~MovableElement() {

}

void MovableElement::move()
{
    _x += _dx;
    _y += _dy;
}

int MovableElement::getX() const
{
    return _x;
}

int MovableElement::getY() const
{
    return _y;
}

int MovableElement::getDx() const
{
    return _dx;
}

int MovableElement::getDy() const
{
    return _dy;
}

int MovableElement::getH() const
{
    return _h;
}

int MovableElement::getW() const
{
    return _w;
}

void MovableElement::setX(int x) {
    _x = x;
}

void MovableElement::setY(int y) {
    _y = y;
}

void MovableElement::setDx(int dx)
{
    _dx = dx;
}

void MovableElement::setDy(int dy)
{
    _dy = dy;
}

bool MovableElement::enJeu() const
{
    if((_x+_w) < 0)
        return false;
    return true;
}

bool MovableElement::collision(MovableElement *element) const
{
    return false;
}

std::string MovableElement::getType() const {
    return "Objet inconnu";
}
