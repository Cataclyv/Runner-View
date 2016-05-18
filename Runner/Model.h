#ifndef MODEL_H
#define MODEL_H

#include "Balle.h"
#include "Score.h"
#include "Chunk.h"
#include <vector>

const int LARGEUR_MODEL = 800;
const int HAUTEUR_MODEL = 600;
const int HAUTEUR_SAUT = 100;
const int NB_CHUNKS = 10;
const int VITESSE_BALLE = 10;
const int LARGEUR_CHUNK = 100;
const int ECART = 20;

class Model
{
private :
    int _w, _h;
    Balle *_balle;
    std::vector<Chunk*> _chunks;
    Score *_scoreJoueur;
    int _degatsObstacle;

public:
    Model();
    ~Model();

    void remplirModel();    // A exécuter au lancement du jeu
    void ajouterChunk(int x);
    void ajouterChunk(int x, char type);    // Réservée aux tests
    std::vector<Chunk*> recupererChunks();

    bool nextStep();

    void deplacerBalle(bool aGauche);
    void stopperBalle();
    void sautBalle();

    int getBalleX() const;
    int getBalleY() const;

    bool contientBalle(Chunk *c) const; // Renvoie si le chunk en paramètre contient la balle
};

#endif // MODEL_H
