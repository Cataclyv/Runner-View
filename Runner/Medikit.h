#ifndef MEDIKIT_H
#define MEDIKIT_H

#include <iostream>
#include "Bonus.h"
#include "Balle.h"

class Medikit : public Bonus
{
private :
    int _soins;
public :
    Medikit();
    Medikit(int x);

    int getSoins();
    void setSoins(int montantSoins);

    virtual std::string getType() const;
};

#endif // MEDIKIT_H
