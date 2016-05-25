#ifndef VIEW_H
#define VIEW_H

#include <map>
#include <string>

#include "Model.h"
#include "MovableElement.h"
#include "GraphicElement.h"
#include "SlidingBackground.h"

#include <SFML/Graphics.hpp>

const float POSITION_BARRE_VIE = 10.f;
const float LARGEUR_BARRE_VIE = 20.f;
const float LARGEUR_BOUTON = 200.f;
const float HAUTEUR_BOUTON = 50.f;
const float DECALAGE_BOUTONS = 50;

const int TEMPS_GAME_OVER = 6;

const std::string FONT = "polices/Antique_Olive.ttf";
const std::string IMG_IUT = "images/logo_iut.jpg";
const std::string IMG_BALLE = "images/ball.png";
const std::string IMG_BACKGROUND_FRONT = "images/city_1.png";
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

    /*** BOOLEENS ***/
    bool _dansMenu;
    bool _finJeu;
    bool _reinit;

    /*** TEXTURES ***/
    sf::Texture _textureLogo;
    sf::Texture _textureBackGroundAvant;
    sf::Texture _textureBackGroundArriere;
    sf::Texture _textureBalle;
    sf::Texture _textureObstacle;
    sf::Texture _texturePiece;
    sf::Texture _textureMedikit;

    /*** TEXTES ***/
    sf::Font _font;
    sf::Text _texteScore;
    sf::Text _textePv;
    sf::Text _texteJouer;
    sf::Text _texteQuitter;
    sf::Text _texteFin;

    /*** ELEMENTS GRAPHIQUES ***/
    SlidingBackground *_backGroundAvant, *_backGroundArriere;
    GraphicElement *_logoGraphique;
    GraphicElement *_balleGraphique;
    GraphicElement *_obstacleGraphique;
    GraphicElement *_pieceGraphique;
    GraphicElement *_medikitGraphique;

    /*** FORMES GEOMETRIQUES ***/
    sf::RectangleShape _barreVie;
    sf::RectangleShape _cadreBarreVie;
    sf::RectangleShape _boutonJouer;
    sf::RectangleShape _boutonQuitter;

    /*** GESTION DU TEMPS ***/
    sf::Clock _clock;
    sf::Time _timeFin;

public:
    View(Model *model);
    ~View();

    void draw();
    bool treatEvents();
    void synchronize();

    bool boutonClique(sf::RectangleShape bouton) const;

    /* FONCTIONS D'AFFICHAGE TERMINAL */
    void imageErreur(std::string chemin);
    void imageTrouvee(std::string chemin);
    void policeErreur(std::string chemin);
    void policeTrouvee(std::string chemin);
};

#endif // VIEW_H
