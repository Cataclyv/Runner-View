#include "Balle.h"

Balle::Balle(int hauteur)
    : MovableElement{10, 0, W_BALLE, H_BALLE, 0, 0}, _pv{PV_MAX}, _enSaut{false}, _enChute{false}
{
    _y = hauteur-_w;
}

void Balle::move()
{
    bool deplacable = true;
    if((_x-_dx < 20 && _dx < 0) || (_x+_dx > 800-_w && _dx > 0))
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

bool Balle::getEnChute() const
{
    return _enChute;
}

void Balle::setDx(int dx) {
    _dx = dx;
}

void Balle::setPv(int pv) {
    _pv = pv;
    if(_pv > PV_MAX)
        _pv = PV_MAX;
}

void Balle::setEnSaut(bool saut) {
    _enSaut = saut;
}

void Balle::setEnChute(bool chute)
{
    _enChute = chute;
}
