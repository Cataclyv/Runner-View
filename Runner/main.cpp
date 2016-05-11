#include <iostream>

#include "Model.h"
#include "View.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Model _model;
    View _view;
    _view.setModel(&_model);

    while(_view.treatEvents()){
      _model.nextStep();
      _view.draw();
      _view.synchronize();
    }

    return EXIT_SUCCESS;
}

