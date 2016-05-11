#ifndef VOL_H
#define VOL_H

#include "Bonus.h"
#include <iostream>

#include "Balle.h"

class Vol : public Bonus
{
private:
    int _duree;
public:
    Vol(int x);
    virtual ~Vol();

    void applicationBonus(Balle* b);

    int getDuree() const;
    void setDuree(int duree);
};

#endif // VOL_H
