#include <iostream>

#include "Model.h"

using namespace std;

int main()
{
    Model _model;
    bool enJeu = true;

    while(enJeu) {
        enJeu = _model.nextStep();
    }
}

