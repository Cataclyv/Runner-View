#ifndef BONUS_H
#define BONUS_H

#include <iostream>
#include <string>
#include "MovableElement.h"

const int VAL_PIECE = 10;
const int VAL_BONUS = 50;
const int VAL_CHUNK = 100;
const int TAILLE = 40;

class Bonus : public MovableElement
{
protected:
    int _valPoints;
public:
    Bonus(int x, int valeur);

    void move();

    int getVal() const;

    virtual std::string getType() const;

};

#endif // BONUS_H
