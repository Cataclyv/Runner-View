#ifndef MODEL_H
#define MODEL_H

#include "Balle.h"
#include "Score.h"
#include "Obstacle.h"
#include "Medikit.h"
#include "Piece.h"
#include <set>

const int LARGEUR_MODEL = 800;
const int HAUTEUR_MODEL = 600;
const int HAUTEUR_SAUT = HAUTEUR_MODEL/3;
const int HAUTEUR_SOL = 500;
const int TAILLE_ELEMENTS = 40;
const int VITESSE_BALLE = 10;   // Vitesse de déplacement horizontal
const int VITESSE_INITIALE_JEU = 4;
const int COEFF_GRAVITE = 3;    // Utilisé pour la vitesse de saut
const int MAX_ELEMENTS = 20;
const int ECART_BORNE = 600;
const int ECART_MIN = 50;


class Model
{
private :
    int _ecart;
    int _vitesseJeu;
    int _w, _h;
    Balle *_balle;
    std::set<MovableElement*> _elements;
    Score *_scoreJoueur;
    int _degatsObstacle;

public:
    Model();
    ~Model();

    void calculerEcart();
    void ajouterElementAleatoire(int coefficient);

    bool nextStep();
    void rajouterElement();

    void deplacerBalle(bool aGauche);
    void stopperBalle();
    void sautBalle();
    void bougerBalle();

    int getBalleX() const;
    int getBalleY() const;
    int getVitesseJeu() const;
    bool balleAuSol() const;

    std::set<MovableElement*> recupererElements() const;
};

#endif // MODEL_H
