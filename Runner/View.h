#ifndef VIEW_H
#define VIEW_H

#include <map>
#include <string>

#include "Model.h"
#include "MovableElement.h"
#include "GraphicElement.h"
#include "SlidingBackground.h"

#include <SFML/Graphics.hpp>

const int VIEW_WIDTH = 800;
const int VIEW_HEIGHT = 600;

const std::string IMG_BALLE = "../Runner/img/ball.png";
const std::string IMG_BACKGROUND_FRONT = "../Runner/img/city_2.png";
const std::string IMG_BACKGROUND_BACK = "../Runner/img/city_1.png";

class View
{
private :
    int _w, _h;
    sf::RenderWindow *_window;
    Model *_model;

    SlidingBackground *_backGroundAvant, *_backGroundArriere;
    GraphicElement *g_balle;

    std::map<const MovableElement*, GraphicElement*> _movableToGraphic;

public:
    View();
    ~View();

    void setModel(Model *model);
    void draw();
    bool treatEvents();
    void synchronize();

    /* FONCTIONS D'AFFICHAGE TERMINAL */
    void erreurImage(std::string chemin);
    void imageTrouvee(std::string chemin);
};

#endif // VIEW_H
