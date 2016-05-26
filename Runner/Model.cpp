#include "Model.h"

using namespace std;

Model::Model() : _ecart{50}, _vitesseJeu{VITESSE_INITIALE_JEU}, _w{LARGEUR_JEU}, _h {HAUTEUR_JEU}, _degatsObstacle{25}, _soins{25} {
    _balle = new Balle(HAUTEUR_SOL);
    if(VERBOSE)
        cout << "Balle crée aux coordonnées (" << _balle->getX() << ", " << _balle->getY() << ")" << endl << endl;
    _scoreJoueur = new Score();

    /*** REMPLISSAGE MODELE ***/
    rajouterElement(true);
    for(int i=1 ; i<MAX_ELEMENTS ; i++) {
        rajouterElement(false);
    }
}

Model::~Model() {
    delete _scoreJoueur;
    delete _balle;
    for(MovableElement* e : _elements)
        delete e;
}

void Model::calculerEcart()
{
    srand(time(NULL)+_ecart);
    _ecart = (rand()%ECART_BORNE) + TAILLE_ELEMENTS + ECART_MIN;
    if(VERBOSE)
        cout << "ECART -> " << _ecart << endl;
}

void Model::ajouterElementAleatoire(int xCourant)
{
    MovableElement *nouvelElement;
    int determination_element = rand()%100;

    if(determination_element < 60) {
        int determination_obstacle = rand()%100;
        if(determination_obstacle < 70) {
            nouvelElement = new Obstacle(xCourant, HAUTEUR_SOL-TAILLE_ELEMENTS, TAILLE_ELEMENTS, TAILLE_ELEMENTS, -_vitesseJeu, 0, OBSTACLE_BASE);
            _elements.insert(nouvelElement);
        }
        else if(determination_obstacle < 90) {
            nouvelElement = new Obstacle(xCourant, HAUTEUR_SOL-3*TAILLE_ELEMENTS, TAILLE_ELEMENTS, TAILLE_ELEMENTS, -_vitesseJeu, 0, OBSTACLE_AIR);
            _elements.insert(nouvelElement);
        }
        else {
            nouvelElement = new Obstacle(xCourant, HAUTEUR_SOL-2*TAILLE_ELEMENTS, 2*TAILLE_ELEMENTS, 2*TAILLE_ELEMENTS, -_vitesseJeu, 0, OBSTACLE_GRAND);
            _elements.insert(nouvelElement);
        }
    }
    else {
        int determination_bonus = rand()%100;

        if(determination_bonus < 90) {
            nouvelElement = new Bonus(xCourant,TAILLE_ELEMENTS, _vitesseJeu, PIECE);
            _elements.insert(nouvelElement);
        }
        else {
            nouvelElement = new Bonus(xCourant,TAILLE_ELEMENTS, _vitesseJeu, MEDIKIT);
            _elements.insert(nouvelElement);
        }
    }
    if(VERBOSE)
        nouvelElement->verbose();
}
    // Quand le jeu sera Game Over, retourne FALSE
bool Model::nextStep() {
    bool continuer = true;

    bool elementSupprime = false;
    for(auto e : _elements) {
        /*** Si le MovableElement sort du jeu ***/
        if(!e->enJeu()) {
            if(VERBOSE)
                cout << "SCORE COURANT -> " << _scoreJoueur->score() << endl;
            _elements.erase(e);
            delete e;
            elementSupprime = true;
        }
        else
            e->move();
    }
    if(elementSupprime) {
        rajouterElement(false);
        if(VERBOSE)
            cout << "TAILLE LISTE >>> " << _elements.size() << endl;
    }

    gestionSautBalle();

    /*** GESTION COLLISION ***/
    MovableElement *elementTouche = nullptr;
    for(auto e : _elements) {
        if(e->collision(_balle)) {
            if(e->getType() == OBSTACLE_BASE || e->getType() == OBSTACLE_AIR || e->getType() == OBSTACLE_GRAND) {
                _balle->setPv(_balle->getPv()-_degatsObstacle);
                if(VERBOSE)
                    cout << "Le joueur perd " << _degatsObstacle << " PV ; il lui en reste " << _balle->getPv() << endl;
            }
            else {
                if(e->getType() == MEDIKIT) {
                    _balle->setPv(_balle->getPv()+_soins);
                    if(VERBOSE)
                        cout << "Le joueur a ramassé un médikit et est passé à " << _balle->getPv() << " PV" << endl;
                    _scoreJoueur->plusBonus();
                }

                else if(e->getType() == PIECE) {
                    if(VERBOSE)
                        cout << "Le joueur a ramassé une pièce" << endl;
                    _scoreJoueur->plusPiece();
                }
            }
            elementTouche = e;
        }
    }
    if(elementTouche != nullptr) {
        _elements.erase(elementTouche);
        delete elementTouche;
        rajouterElement(false);
        if(VERBOSE)
            cout << "TAILLE LISTE >>> " << _elements.size() << endl;
    }

    /*** Détection mort du joueur ***/
    if(_balle->getPv() <= 0) {
        cout << endl << "Mort du joueur" << endl;
        continuer = false;
    }
    return continuer;
}

void Model::rajouterElement(bool debutJeu)
{
    calculerEcart();
    int xAgauche = 0;
    for(auto e : _elements) {
        if(e->getX() > xAgauche)
            xAgauche = e->getX();
    }
    if(debutJeu)
        ajouterElementAleatoire(xAgauche + _ecart + LARGEUR_JEU);
    else
        ajouterElementAleatoire(xAgauche + _ecart);
}

void Model::deplacerBalle(bool aGauche) {
    if(aGauche && !_balle->getEnSaut())
        _balle->setDx(-VITESSE_BALLE);
    else if(!aGauche && !_balle->getEnSaut())
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

int Model::getBalleW() const
{
    return _balle->getW();
}

int Model::getBalleH() const
{
    return _balle->getH();
}

int Model::getPvBalle() const
{
    return _balle->getPv();
}

int Model::getVitesseJeu() const
{
    return _vitesseJeu;
}

int Model::getScore() const
{
    return _scoreJoueur->score();
}

bool Model::balleAuSol() const
{
    return (_balle->getY() + _balle->getH() == HAUTEUR_SOL);
}

std::set<MovableElement*> Model::recupererElements() const
{
    return _elements;
}

void Model::ajouterTempsAuScore()
{
    _scoreJoueur->plusTemps();
}

void Model::stopperBalle()
{
    if(!_balle->getEnSaut())
        _balle->setDx(0);
}

void Model::sautBalle()
{
    _balle->setEnSaut(true);
}

void Model::gestionSautBalle()
{
    if(_balle->getEnSaut() == true) {
        if(_balle->getEnChute() == false) {
            _balle->setDy(-COEFF_GRAVITE*_vitesseJeu);
            if(_balle->getY() < HAUTEUR_SAUT) {
                _balle->setEnChute(true);
            }
        }
        else if(_balle->getEnChute() == true) {
            _balle->setDy(COEFF_GRAVITE*_vitesseJeu);
            if(_balle->getY() + _balle->getH() > HAUTEUR_SOL) {
                _balle->setEnChute(false);
                _balle->setEnSaut(false);
                _balle->setDy(0);
                _balle->setDx(0);
                _balle->setY(HAUTEUR_SOL-_balle->getH());
            }
        }
    }
    _balle->move();
}

void Model::setPvBalle(int pv)
{
    _balle->setPv(pv);
}
