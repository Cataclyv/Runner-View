#ifndef VIEW_H
#define VIEW_H

#include <map>
#include <string>

#include "Model.h"
#include "MovableElement.h"
#include "GraphicElement.h"
#include "SlidingBackground.h"
#include "ecranintroduction.h"

#include <SFML/Graphics.hpp>

const int VIEW_WIDTH = 800;
const int VIEW_HEIGHT = 600;
const float POSITION_BARRE_VIE = 10.f;
const float LARGEUR_BARRE_VIE = 20.f;

const std::string FONT = "polices/Antique_Olive.ttf";
const std::string IMG_BALLE = "images/ball.png";
const std::string IMG_BACKGROUND_FRONT = "images/Fond_Marin.png";
const std::string IMG_BACKGROUND_BACK = "images/city_2.png";
const std::string IMG_OBSTACLE = "images/obstacle.png";
const std::string IMG_PIECE = "images/piece.png";
const std::string IMG_MEDIKIT = "images/medikit.png";

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
    sf::Texture _texturePiece;
    sf::Texture _textureMedikit;
    sf::Texture _introImg1;
    sf::Texture _introImg2;

    /*** TEXTES ***/
    sf::Font _font;
    sf::Text _texteScore;
    sf::Text _textePv;

    /*** ELEMENTS GRAPHIQUES ***/
    SlidingBackground *_backGroundAvant, *_backGroundArriere;
    GraphicElement *_balleGraphique;
    GraphicElement *_obstacleGraphique;
    GraphicElement *_pieceGraphique;
    GraphicElement *_medikitGraphique;
    GraphicElement *_introImgSprite1;
    GraphicElement *_introImgSprite2;
    ecranIntroduction m_introduction;

    /*** FORMES GEOMETRIQUES ***/
    sf::RectangleShape _barreVie;
    sf::RectangleShape _cadreBarreVie;

    /*** GESTION DU TEMPS ***/
    sf::Clock _clock;
    sf::Time _time;

public:
    View(Model *model);
    ~View();

    void draw();
    bool treatEvents();
    void synchronize();

    /* FONCTIONS D'AFFICHAGE TERMINAL */
    void imageErreur(std::string chemin);
    void imageTrouvee(std::string chemin);
    void policeErreur(std::string chemin);
    void policeTrouvee(std::string chemin);
};

#endif // VIEW_H
