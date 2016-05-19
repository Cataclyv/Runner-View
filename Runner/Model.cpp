#include "Model.h"

Model::Model() : _ecart{50}, _w{LARGEUR_MODEL}, _h {HAUTEUR_MODEL}, _degatsObstacle{25}
{
    _balle = new Balle();
    std::cout << "Balle crée aux coordonnées (" << _balle->getX() << ", " << _balle->getY() << ")" << std::endl << std::endl;
    _scoreJoueur = new Score();

    /*** REMPLISSAGE MODELE ***/
    for(int i=0 ; i<MAX_ELEMENTS ; i++) {
        _ecart = rand()%200 + ECART_MIN;
        ajouterElementAleatoire(_w+i*_ecart);
    }
}

Model::~Model() {
    delete _balle;
    for(MovableElement* e : _elements)
        delete e;
}

void Model::ajouterElementAleatoire(int xCourant)
{
    srand(time(NULL));
    int determination_element = rand()%100;
    if(determination_element < 70)
        _elements.insert(new Obstacle(xCourant, 450, 40, 40, -1, 0));
    else if(determination_element >= 70 && determination_element < 85) {
        int determination_bonus = rand()%100;
        if(determination_bonus < 90)
            _elements.insert(new Piece(xCourant));
        else
            _elements.insert(new Medikit(xCourant));
    }
}
    // Quand le jeu sera Game Over, retourne FALSE
bool Model::nextStep() {

    int elementSupprime = false;
    for(auto e : _elements) {

        /*** Si le MovableElement sort du jeu ***/
        if(!e->enJeu()) {
            //_chunks.pop_back();
            _scoreJoueur->plusObstacle();
            _elements.erase(e);
            elementSupprime = true;
        }
        e->move();
    }
    if(elementSupprime)
        ajouterElementAleatoire(800);
/*
    if(_balle->getEnSaut() && _balle->getY() < HAUTEUR_SAUT)
    {
        _balle->setDy(1);
        if(_balle->getX() >= HAUTEUR_SAUT )
            _balle->setEnSaut(false);
    }
    else if(!_balle->getEnSaut() && _balle->getY() > 10)
    {
        _balle->setDy(-1);
    }*/
    _balle->move();

    for(auto e : _elements) {
        if(e->collision(_balle)) {
            if(e->getType() == "Obstacle") {
                _balle->setPv(_balle->getPv()-_degatsObstacle);
            }
            else {
                if(e->getType() == "Medikit") {
                    Medikit reference;
                    _balle->setPv(_balle->getPv() + reference.getSoins());
                    if(_balle->getPv() > PV_MAX)
                        _balle->setPv(PV_MAX);
                    _scoreJoueur->plusBonus();
                }

                else if(e->getType() == "Piece") {
                    _scoreJoueur->plusPiece();
                }
            }
        }
    }

    /*** Détection mort du joueur ***/
    if(_balle->getPv() <= 0) {
        std::cout << "Mort du joueur" << std::endl;
        return false;
    }
    return false;
}

void Model::deplacerBalle(bool aGauche) {
    if(aGauche)
        _balle->setDx(-VITESSE_BALLE);
    else
        _balle->setDx(VITESSE_BALLE);
    _balle->move();
}

int Model::getBalleX() const
{
    return _balle->getX();
}

int Model::getBalleY() const
{
    return _balle->getY();
}

std::set<MovableElement*> Model::recupererElements() const
{
    return _elements;
}

void Model::stopperBalle()
{
    _balle->setDx(0);
}

void Model::sautBalle()
{
    _balle->setEnSaut(true);
}
