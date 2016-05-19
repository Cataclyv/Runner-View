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

const std::string FONT = "Antique Olive.tff";
const std::string IMG_BALLE = "img/ball.png";
const std::string IMG_BACKGROUND_FRONT = "img/city_1.png";
const std::string IMG_BACKGROUND_BACK = "img/city_2.png";
const std::string IMG_OBSTACLE = "img/ball.png";

class View
{
private :
    int _w, _h;
    sf::RenderWindow *_window;
    Model *_model;

    /*** TEXTURES ***/
    sf::Texture _textureBackGroundAvant;
    sf::Texture _textureBackGroundArriere;
    sf::Texture _textureBalle;
    sf::Texture _textureObstacle;

    sf::Font _font;
    sf::Text _texteScore;

    SlidingBackground *_backGroundAvant, *_backGroundArriere;
    GraphicElement *_balleGraphique;
    GraphicElement *_obstacleGraphique;

    //std::map<const MovableElement*, GraphicElement*> _movableToGraphic;

public:
    View(Model *model);
    ~View();

    void draw();
    bool treatEvents();
    void synchronize();

    /* FONCTIONS D'AFFICHAGE TERMINAL */
    void imageErreur(std::string chemin);
    void imageTrouvee(std::string chemin);
};

#endif // VIEW_H
