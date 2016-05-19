#include "Medikit.h"

Medikit::Medikit() : Bonus(-100, VAL_BONUS), _soins(25) {

}

Medikit::Medikit(int x)
    : Bonus(x, VAL_BONUS), _soins(25)
{
    std::cout << " -> Medikit" << std::endl;
}

int Medikit::getSoins() const {
    std::cout << "SOINS -> " <<_soins << " PV" << std::endl;
    return _soins;
}

void Medikit::setSoins(int montantSoins)
{
    _soins = montantSoins;
    std::cout << "Les soins sont de" << _soins << std::endl;
}

std::string Medikit::getType() const {
    return "Medikit";
}
