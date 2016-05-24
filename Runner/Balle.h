#ifndef BALLE_H
#define BALLE_H

#include "MovableElement.h"

const int W_BALLE = 50;
const int H_BALLE = 50;
const int PV_MAX = 1000;

class Balle : public MovableElement
{
private :
    int _score;
    int _pv;
    bool _enSaut, _enChute;
public:
    Balle(int hauteur);
    virtual ~Balle();

    void move() override;

    int getPv() const;
    bool getEnSaut() const;
    bool getEnChute() const;

    void setDx(int dx);
    void setPv(int pv);
    void setEnSaut(bool saut);
    void setEnChute(bool chute);
};

#endif // BALLE_H
