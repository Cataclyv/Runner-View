#include <iostream>

#include "Model.h"
#include "View.h"

using namespace std;

int main()
{
    srand(time(NULL));
    View _view;
    Model _model;
    _view.setModel(&_model);
    _view.genererView();

    while(_view.treatEvents()){
      _model.nextStep();
      _view.draw();
      _view.synchronize();
    }

    return EXIT_SUCCESS;
}

