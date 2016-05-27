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

/**
 * @brief TEMPS_GAME_OVER
 * CONSTANTE -> Durée de l'écran de game over
 */
const int TEMPS_GAME_OVER = 6;

const std::string FONT = "polices/Antique_Olive.ttf";
const std::string IMG_IUT = "images/logo_iut.jpg";
const std::string IMG_BALLE = "images/ball.png";
const std::string IMG_BACKGROUND_FRONT = "images/city_1.png";
const std::string IMG_BACKGROUND_BACK = "images/city_2.png";
const std::string IMG_OBSTACLE_BASE = "images/obstacle_base.png";
const std::string IMG_OBSTACLE_AIR = "images/obstacle_air.png";
const std::string IMG_OBSTACLE_GRAND = "images/obstacle_grand.png";
const std::string IMG_PIECE = "images/piece.png";
const std::string IMG_MEDIKIT = "images/medikit.png";

class View
{
private :
    /**
     * @brief _w
     * Largeur de la vue, égale à la largeur de l'espace de jeu
     */
    int _w;
    /**
     * @brief _h
     * Hauteur de la vue, égale à la hauteur de l'espace de jeu
     */
    int _h;
    /**
     * @brief _window
     * Fenêtre SFML dans laquelle le jeu est affiché
     */
    sf::RenderWindow *_window;
    /**
     * @brief _model
     * Modèle utilisé pour gérer les données du jeu
     */
    Model *_model;

    /**
     * @brief _dansMenu
     * Détermine si le menu doit être affiché et utilisé
     */
    bool _dansMenu;
    /**
     * @brief _finJeu
     * Détermine si le jeu est terminé et donc l'écran de game over affiché
     */
    bool _finJeu;
    /**
     * @brief _reinit
     * Détermine si le modèle doit être réinitialisé
     */
    bool _reinit;

    /**
     * @brief _dansIntro
     * Détermine si le jeu affiche l'écran d'introduction
     */
    bool _dansIntro;

    /*** TEXTURES ***/
    sf::Texture _textureLogo;
    sf::Texture _textureBackGroundAvant;
    sf::Texture _textureBackGroundArriere;
    sf::Texture _textureBalle;
    sf::Texture _textureObstacleBase;
    sf::Texture _textureObstacleAir;
    sf::Texture _textureObstacleGrand;
    sf::Texture _texturePiece;
    sf::Texture _textureMedikit;

    /*** TEXTES ***/
    /**
     * @brief _font
     * Police d'écriture utilisée pour les textes
     */
    sf::Font _font;
    sf::Text _texteScore;
    sf::Text _textePv;
    sf::Text _texteJouer;
    sf::Text _texteQuitter;
    sf::Text _texteFin;
    sf::Text _titre;
    sf::Text _texteIntro;

    /*** ELEMENTS GRAPHIQUES ***/
    SlidingBackground *_backGroundAvant, *_backGroundArriere;
    GraphicElement *_logoGraphique;
    GraphicElement *_balleGraphique;
    GraphicElement *_elementGraphique;

    /*** FORMES GEOMETRIQUES ***/
    sf::RectangleShape _barreVie;
    sf::RectangleShape _cadreBarreVie;
    sf::RectangleShape _boutonJouer;
    sf::RectangleShape _boutonQuitter;

    /*** GESTION DU TEMPS ***/
    sf::Clock _horloge;
    /**
     * @brief _tempsFin
     * Gère le temps de l'écran de game over
     */
    sf::Time _tempsFin;
    /**
     * @brief _tempsScore
     * Utilisé pour gérer l'incrémentation du score avec le temps
     */
    sf::Time _tempsScore;

    /**
     * @brief _tempsIntro
     * Gère le temps de l'écran d'introduction
     */
    sf::Time _tempsIntro;

public:
    /**
     * @brief View
     * @param model
     */
    View(Model *model);
    ~View();

    /**
     * @brief draw
     * Dessine l'intégralité de la vue dans la fenêtre
     */
    void draw();
    /**
     * @brief treatEvents
     * @return
     * Détecte et gère les évènements claviers et souris
     */
    bool treatEvents();
    /**
     * @brief synchronize
     * Synchronise la position de la balle graphique avec la position de la balle du modèle et augmente le score du joueur avec le temps
     */
    void synchronize();

    /**
     * @brief boutonClique
     * @param bouton
     * @return
     * Détermine si, lors d'un clic, la souris se situe sur un bouton du menu
     */
    bool boutonClique(sf::RectangleShape bouton) const;

    /**
     * @brief imageErreur
     * @param chemin
     * Affiche dans le terminal si le fichier image n'a pas pu être trouvé à l'emplacement spécifié
     */
    void imageErreur(std::string chemin);
    /**
     * @brief imageTrouvee
     * @param chemin
     * Affiche dans le terminal si le fichier image a pu être trouvé à l'emplacement spécifié
     */
    void imageTrouvee(std::string chemin);
    /**
     * @brief policeErreur
     * @param chemin
     * Affiche dans le terminal si la police d'écriture n'a pas pu être trouvé à l'emplacement spécifié
     */
    void policeErreur(std::string chemin);
    /**
     * @brief policeTrouvee
     * @param chemin
     * Affiche dans le terminal si la police d'écriture a pu être trouvé à l'emplacement spécifié
     */
    void policeTrouvee(std::string chemin);
};

#endif // VIEW_H
