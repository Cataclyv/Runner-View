#ifndef MODEL_H
#define MODEL_H

#include "Balle.h"
#include "Score.h"
#include "Chunk.h"
#include <set>

const int LARGEUR_MODEL = 800;
const int HAUTEUR_MODEL = 600;
const int HAUTEUR_SAUT = 100;
const int NB_CHUNKS = 10;
const int VITESSE_BALLE = 10;
const int MAX_ELEMENTS = 20;
const int ECART_MIN = 40;

class Model
{
private :
    int _ecart;
    int _w, _h;
    Balle *_balle;
    std::set<MovableElement*> _elements;
    Score *_scoreJoueur;
    int _degatsObstacle;

public:
    Model();
    ~Model();

    void ajouterElementAleatoire(int coefficient);

    bool nextStep();

    void deplacerBalle(bool aGauche);
    void stopperBalle();
    void sautBalle();

    int getBalleX() const;
    int getBalleY() const;

    std::set<MovableElement*> recupererElements() const;
};

#endif // MODEL_H
