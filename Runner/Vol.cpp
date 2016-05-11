#include "Vol.h"

Vol::Vol(int x)
    : Bonus(x, VAL_BONUS), _duree(5)
{
    std::cout << " -> Vol" << std::endl;
}

Vol::~Vol() {

}

int Vol::getDuree() const
{
    std::cout << _duree << std::endl;
    return _duree;
}

void Vol::setDuree(int duree)
{
    _duree = duree;
    std::cout << "La duree de ce bonus est de : " << duree << std::endl;
}

