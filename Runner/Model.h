#ifndef MODEL_H
#define MODEL_H

#include "Balle.h"
#include "Score.h"
#include "Chunk.h"
#include <vector>

const int MODEL_WIDTH = 800;
const int MODEL_HEIGHT = 600;
const int HAUTEUR_SAUT = 100;
const int NB_CHUNKS = 10;

class Model
{
private :
    int _w, _h;
    Balle *_balle;
    std::vector<Chunk*> _elements;
    Score *_scoreJoueur;
    int _degatsObstacle;

public:
    Model();
    ~Model();

    void remplirModel();    // A exécuter au lancement du jeu
    void ajouterChunk(int x);
    void ajouterChunk(int x, char type);    // Réservée aux tests
    bool nextStep();
    void deplacerBalle(bool aGauche);
    void positionBalle(int &x, int &y);

    bool contientBalle(Chunk *c) const; // Renvoie si le chunk en paramètre contient la balle
};

#endif // MODEL_H
