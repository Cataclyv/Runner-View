#ifndef INVINCIBILITE_H
#define INVINCIBILITE_H

#include "Bonus.h"
#include "Balle.h"
#include <iostream>

class Invincibilite : public Bonus
{
protected:
    int _duree;
public:
    Invincibilite(int x);

    void applicationBonus(Balle* b);

    int getDuree() const;
    void setDuree(int duree);

    virtual std::string getType() const;
};

#endif // INVINCIBILITE_H
