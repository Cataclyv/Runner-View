#include "Model.h"

Model::Model() : _w{MODEL_WIDTH}, _h {MODEL_HEIGHT}, _degatsObstacle{25}
{
    _balle = new Balle();
    _scoreJoueur = new Score();
}

Model::~Model() {
    delete _balle;
    for(Chunk* c : _elements)
        delete c;
}

void Model::remplirModel() {
    int ecart = 20;
    for(int i=0 ; i<NB_CHUNKS ; i++)
    {
        ajouterChunk(i*100+ecart);
    }
}

void Model::ajouterChunk(int x) {
    int determination_chunk = rand()%100;
    if(determination_chunk < 70)
        _elements.push_back(new Chunk(x, 2));
    else if(determination_chunk >= 70 && determination_chunk < 85)
        _elements.push_back(new Chunk(x, 1));
    else if(determination_chunk >= 85)
        _elements.push_back(new Chunk(x, 0));
}

void Model::ajouterChunk(int x, char type) {
    switch(type) {
    case 'v' :
        _elements.push_back(new Chunk(x, 0));
        break;
    case 'o' :
        _elements.push_back(new Chunk(x, 2));
        break;
    case 'b' :
         _elements.push_back(new Chunk(x, 1));
        break;
    }
}

    // Quand le jeu sera Game Over, retourne FALSE
bool Model::nextStep() {

    for(auto e : _elements) {

        if(!e->enJeu()) //si le MovableElement sort du jeu
            _elements.pop_back();

        if(_elements.size() < NB_CHUNKS) {  // crée un nouveau Chunk quand il en manque
            ajouterChunk(1020);
        }
        e->move();
    }

    if(_balle->getEnSaut() && _balle->getY() < HAUTEUR_SAUT)
    {
        _balle->setDy(1);
        if(_balle->getX() >= HAUTEUR_SAUT )
            _balle->setEnSaut(false);
    }
    else if(!_balle->getEnSaut() && _balle->getY() > 10)
    {
        _balle->setDy(-1);
    }
    _balle->move();

    // Détection collision-objet
    for(auto e : _elements) {
        if(contientBalle(e) && e->collision(_balle)) {

            std::string typeObjetTouche = e->objetTouche();

            if(typeObjetTouche == "Obstacle") {
                _balle->setPv(_balle->getPv()-_degatsObstacle);
            }

            else {

                if(typeObjetTouche == "Medikit") {
                    Medikit reference;
                    _balle->setPv(_balle->getPv() + reference.getSoins());
                    if(_balle->getPv() > PV_MAX)
                        _balle->setPv(PV_MAX);
                    _scoreJoueur->plusBonus();
                }

                else if(typeObjetTouche == "Piece") {
                    _scoreJoueur->plusPiece();
                }

                else if(typeObjetTouche == "Invincibilite") {
                    _scoreJoueur->plusBonus();
                }

                else if(typeObjetTouche == "Vol") {
                    _scoreJoueur->plusBonus();
                }
            }
        }
    }

    std::cout << std::endl;

    if(_balle->getPv() <= 0) {
        std::cout << "Mort du joueur" << std::endl;
        return false;
    }
    return false;
}

void Model::deplacerBalle(bool aGauche) {
    if(aGauche)
        _balle->setDx(-1);
    else
        _balle->setDx(1);
    _balle->move();
    _balle->setDx(0);
}

void Model::positionBalle(int &x, int &y) {
    x = _balle->getX();
    y = _balle->getY();
}

bool Model::contientBalle(Chunk *e) const
{
    bool contient = false;
    if((_balle->getX()+_balle->getW() > e->getX() && _balle->getX()+_balle->getW() < e->getX()+e->getW())
            || (_balle->getX() > e->getX() && _balle->getX() < e->getX()+e->getW()))
    {
        contient = true;
    }
    return contient;
}
