#include "Balle.h"

Balle::Balle()
    : MovableElement{10, 450, W_BALLE, H_BALLE, 0, 0}, _pv{PV_MAX}, _enSaut{false}
{
}

Balle::~Balle() {

}

void Balle::move()
{
    bool deplacable = true;
    if((_x-_dx < 20 && _dx < 0) || (_x+_w+_dx > 710 && _dx > 0))
        deplacable = false;
    if(deplacable)
        _x += _dx;
    _y += _dy;
}

int Balle::getPv() const {
    return _pv;
}

bool Balle::getEnSaut() const {
    return _enSaut;
}

void Balle::setDx(int dx) {
    _dx = dx;
}

void Balle::setPv(int pv) {
    _pv = pv;
}

void Balle::setEnSaut(bool saut) {
    _enSaut = saut;
}
