#include "Model.h"

using namespace std;

Model::Model() : _ecart{50}, _vitesseJeu{VITESSE_INITIALE_JEU}, _w{LARGEUR_MODEL}, _h {HAUTEUR_MODEL}, _degatsObstacle{25}
{
    _balle = new Balle(HAUTEUR_SOL);
    cout << "Balle crée aux coordonnées (" << _balle->getX() << ", " << _balle->getY() << ")" << endl << endl;
    _scoreJoueur = new Score();

    /*** REMPLISSAGE MODELE ***/
    for(int i=0 ; i<MAX_ELEMENTS ; i++) {
        calculerEcart();
        ajouterElementAleatoire(_w+i*_ecart);
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
    _ecart = (rand()%ECART_BORNE) + ECART_MIN;
    //cout << "ECART -> " << _ecart << endl;
}

void Model::ajouterElementAleatoire(int xCourant)
{
    int determination_element = rand()%100;

    if(determination_element < 70)
        _elements.insert(new Obstacle(xCourant, HAUTEUR_SOL-TAILLE_ELEMENTS, TAILLE_ELEMENTS, TAILLE_ELEMENTS, -_vitesseJeu, 0));
    else if(determination_element >= 70 && determination_element < 85) {
        int determination_bonus = rand()%100;

        if(determination_bonus < 90)
            _elements.insert(new Piece(xCourant, -_vitesseJeu));
        else
            _elements.insert(new Medikit(xCourant, -_vitesseJeu));
    }
}
    // Quand le jeu sera Game Over, retourne FALSE
bool Model::nextStep() {

    int elementSupprime = false;
    for(auto e : _elements) {
        /*** Si le MovableElement sort du jeu ***/
        if(!e->enJeu()) {
            _scoreJoueur->plusObstacle();
            cout << "SCORE COURANT -> " << _scoreJoueur->score() << endl;
            _elements.erase(e);
            delete e;
            elementSupprime = true;
        }
        else
            e->move();
    }
    if(elementSupprime) // Si un élément a été supprimé, en rajoute un nouveau
    {
        rajouterElement();
    }

    bougerBalle();

    /*** GESTION COLLISION ***/
    for(auto e : _elements) {
        if(e->collision(_balle)) {
            if(e->getType() == "Obstacle") {
                _balle->setPv(_balle->getPv()-_degatsObstacle);
                cout << "Le joueur perd " << _degatsObstacle << " PV ; il lui en reste " << _balle->getPv() << endl;
                rajouterElement();
            }
            else {
                if(e->getType() == "Medikit") {
                    _balle->setPv(_balle->getPv()+25);
                    cout << "Le joueur a ramassé un médikit et est passé à " << _balle->getPv() << " PV" << endl;
                    _scoreJoueur->plusBonus();
                    rajouterElement();
                }

                else if(e->getType() == "Piece") {
                    cout << "Le joueur a ramassé une pièce" << endl;
                    _scoreJoueur->plusPiece();
                    rajouterElement();
                }
            }
            _elements.erase(e);
        }
    }

    /*** Détection mort du joueur ***/
    if(_balle->getPv() <= 0) {
        cout << "Mort du joueur" << endl;
        return false;
    }
    return true;
}

void Model::rajouterElement()
{
    calculerEcart();
    ajouterElementAleatoire(LARGEUR_MODEL + _ecart);
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

int Model::getVitesseJeu() const
{
    return _vitesseJeu;
}

bool Model::balleAuSol() const
{
    return (_balle->getY() + _balle->getH() == HAUTEUR_SOL);
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

void Model::bougerBalle()
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
                _balle->setY(HAUTEUR_SOL-_balle->getH());
            }
        }
    }
    _balle->move();
}
