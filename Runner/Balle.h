#ifndef BALLE_H
#define BALLE_H

#include "MovableElement.h"

const int W_BALLE = 50;
const int H_BALLE = 50;
const int PV_MAX = 100;

class Balle : public MovableElement
{
private :
    int _score;
    int _pv;
    bool _enSaut;
public:
    Balle();
    virtual ~Balle();

    void move() override;

    int getPv() const;
    bool getEnSaut() const;

    void setDx(int dx);
    void setPv(int pv);
    void setEnSaut(bool saut);
};

#endif // BALLE_H
