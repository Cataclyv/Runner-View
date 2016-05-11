#ifndef VIEW_H
#define VIEW_H

#include <map>
#include <string>

#include "Model.h"
#include "MovableElement.h"
#include "GraphicElement.h"

#include <SFML/Graphics.hpp>

const int VIEW_WIDTH = 800;
const int VIEW_HEIGHT = 600;

const std::string IMG_BALLE = "./img/ball.png";

class View
{
private :
    int _w, _h;
    sf::RenderWindow *_window;
    Model *_model;

    GraphicElement *g_balle;

    std::map<const MovableElement*, GraphicElement*> _movableToGraphic;

public:
    View();
    ~View();

    void setModel(Model *model);
    void draw();
    bool treatEvents();
    void synchronize();
};

#endif // VIEW_H
