#include <iostream>

#include "Model.h"
#include "View.h"

using namespace std;

int main()
{
    Model _model;
    View _view{&_model};

    while(_view.treatEvents()){
      _view.draw();
      _view.synchronize();
    }

    cout << endl;

    return EXIT_SUCCESS;
}
