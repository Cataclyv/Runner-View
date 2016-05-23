#ifndef BONUS_H
#define BONUS_H

#include <iostream>
#include <string>
#include "MovableElement.h"

const int TAILLE = 40;

class Bonus : public MovableElement
{
protected:
    std::string _type;
public:
    Bonus(int x, int vitesse, std::string type);

    void move();

    int getVal() const;

    virtual std::string getType() const;

};

#endif // BONUS_H
