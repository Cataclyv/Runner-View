#ifndef MODEL_H
#define MODEL_H

#include "Balle.h"
#include "Score.h"
#include "Obstacle.h"
#include "Bonus.h"
#include <set>

/**
 * @brief LARGEUR_JEU
 * CONSTANTE -> Largeur de l'espace de jeu, attribuée au modèle
 */
const int LARGEUR_JEU = 800;
/**
 * @brief HAUTEUR_JEU
 * CONSTANTE -> Hauteur de l'espace de jeu, attribuée au modèle
 */
const int HAUTEUR_JEU = 600;
/**
 * @brief HAUTEUR_SAUT
 * CONSTANTE -> Hauteur jusqu'où la balle va monter lors d'un saut
 */
const int HAUTEUR_SAUT = HAUTEUR_JEU/3;
/**
 * @brief HAUTEUR_SOL
 * CONSTANTE -> Hauteur à laquelle se situe le sol
 */
const int HAUTEUR_SOL = 500;
/**
 * @brief TAILLE_ELEMENTS
 * CONSTANTE -> Taille des obstacles et des bonus
 */
const int TAILLE_ELEMENTS = 60;
/**
 * @brief VITESSE_BALLE
 * CONSTANTE -> Vitesse de déplacement horizontal de la balle
 */
const int VITESSE_BALLE = 7;
/**
 * @brief VITESSE_INITIALE_JEU
 * CONSTANTE -> Vitesse du jeu à son lancement
 */
const int VITESSE_INITIALE_JEU = 3;
/**
 * @brief COEFF_GRAVITE
 * CONSTANTE -> Utilisé pour la vitesse de saut
 */
const int COEFF_GRAVITE = 3;
/**
 * @brief MAX_ELEMENTS
 * CONSTANTE -> Nombre constant d'éléments présents simultanément à la génération du modèle et pendant le jeu
 */
const int MAX_ELEMENTS = 20;
/**
 * @brief ECART_BORNE
 * CONSTANTE -> Ecart maximum entre deux éléments
 */
const int ECART_BORNE = 300;
/**
 * @brief ECART_MIN
 * CONSTANTE -> Ecart minimum entre deux éléments
 */
const int ECART_MIN = 10;

const std::string OBSTACLE_BASE = "ObstacleBase";
const std::string OBSTACLE_AIR = "ObstacleAir";
const std::string OBSTACLE_GRAND = "ObstacleGrand";
const std::string PIECE = "Piece";
const std::string MEDIKIT = "Medikit";

/**
 * @brief VERBOSE
 * Détermine s'il faut activer l'affichage terminal ou non
 */
const bool VERBOSE = true;


class Model
{
private :
    /**
     * @brief _ecart
     * Ecart entre deux éléments, calculé aléatoirement
     */
    int _ecart;
    /**
     * @brief _vitesseJeu
     * Coefficient utilisé pour le déplacement de tous les éléments
     */
    int _vitesseJeu;
    /**
     * @brief _w
     * La largeur du modèle
     */
    int _w;
    /**
     * @brief _h
     * La hauteur du modèle
     */
    int _h;
    /**
     * @brief _balle
     * Pointeur sur la balle
     */
    Balle *_balle;
    /**
     * @brief _elements
     * Collection regroupant tous les obstacles et les bonus
     */
    std::set<MovableElement*> _elements;
    /**
     * @brief _scoreJoueur
     * Pointeur sur le score du joueur, qui regroupe un score total et un pseudonyme
     */
    Score *_scoreJoueur;

    /**
     * @brief _degatsObstacle
     * Dégâts subis par le joueur lors de la collision avec un obstacle
     */
    int _degatsObstacle;
    /**
     * @brief _soins
     * Points de vie rendus au joueur lors de la collision avec un médikit
     */
    int _soins;

public:
    /**
     * @brief Model
     */
    Model();
    ~Model();

    /**
     * @brief calculerEcart
     * Recalcule un nouvel écart aléatoire
     */
    void calculerEcart();
    /**
     * @brief ajouterElementAleatoire
     * @param xCourant
     * Ajoute un nouvel élément déterminé aléatoirement à la coordonnées X spécifiée ; la coordonnée Y est prise en charge par l'élément lui-même
     */
    void ajouterElementAleatoire(int xCourant);

    /**
     * @brief nextStep
     * @return
     * Calcule l'étape suivante en déplaçant, détruisant et générants des éléments et en gérant les collisions
     */
    bool nextStep();
    /**
     * @brief rajouterElement
     * @param debutJeu
     * Rajoute un nouvel élément dans la collection à des coordonnées calculées ; le booléen détermine si l'élément est le tout premier généré
     */
    void rajouterElement(bool debutJeu);

    /**
     * @brief deplacerBalle
     * @param aGauche
     * Déplace la balle selon l'axe horizontal ; méthode utilisée dans la vue
     */
    void deplacerBalle(bool aGauche);
    /**
     * @brief stopperBalle
     * Arrête la balle ; méthode utilisée dans la vue
     */
    void stopperBalle();
    /**
     * @brief sautBalle
     * Fait rentrer la balle en phase de saut
     */
    void sautBalle();
    /**
     * @brief bougerBalle
     * Gère le saut de la balle selon les booléens enSaut et enChute
     */
    void gestionSautBalle();
    /**
     * @brief setPvBalle
     * @param pv
     * Modifie les points de vie de la balle
     */
    void setPvBalle(int pv);

    /**
     * @brief getBalleX
     * @return
     * Retourne la coordonnées X de la balle
     */
    int getBalleX() const;
    /**
     * @brief getBalleY
     * @return
     * Retourne la coordonnée Y de la balle
     */
    int getBalleY() const;
    /**
     * @brief getBalleW
     * @return
     * Retourne la largeur de la balle
     */
    int getBalleW() const;
    /**
     * @brief getBalleH
     * @return
     * Retourne la hauteur de la balle
     */
    int getBalleH() const;
    /**
     * @brief getPvBalle
     * @return
     * Retourne les points de vie de la balle
     */
    int getPvBalle() const;

    /**
     * @brief getVitesseJeu
     * @return
     * Retourne la vitesse du jeu
     */
    int getVitesseJeu() const;
    /**
     * @brief getScore
     * @return
     * Retourne le score total du joueur
     */
    int getScore() const;
    /**
     * @brief balleAuSol
     * @return
     * Retourne si la balle est au sol ou non
     */
    bool balleAuSol() const;

    /**
     * @brief recupererElements
     * @return
     * Retourne la collection d'obstacles et de bonus du modèle ; méthode utilisée dans la vue pour afficher tous les éléments
     */
    std::set<MovableElement*> recupererElements() const;

    /**
     * @brief ajouterTempsAuScore
     * Incrémente le score ; méthode utilisée dans la vue et dépendante du temps
     */
    void ajouterTempsAuScore();
};

#endif // MODEL_H
