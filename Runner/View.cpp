#include "View.h"

using namespace std;

View::View(Model *model) : _w{LARGEUR_JEU}, _h{HAUTEUR_JEU}, _model{model}, _dansMenu{true}
{
    _window = new sf::RenderWindow(sf::VideoMode(_w, _h, 32), "Runner", sf::Style::Close);
    _window->setKeyRepeatEnabled(true);

    _time = _clock.restart();

    /*** CREATION FONT ***/
    if(!_font.loadFromFile(FONT))
        policeErreur(FONT);
    else {
        policeTrouvee(FONT);
    }

    sf::FloatRect bb;

    /*** SLIDINGBACKGROUND AVANT ***/
    if(!_textureBackGroundAvant.loadFromFile(IMG_BACKGROUND_FRONT))
        imageErreur(IMG_BACKGROUND_FRONT);
    else {
        imageTrouvee(IMG_BACKGROUND_FRONT);
        _backGroundAvant = new SlidingBackground(_textureBackGroundAvant, LARGEUR_JEU, HAUTEUR_JEU, _model->getVitesseJeu());
    }

    /*** SLIDINGBACKGROUND ARRIERE ***/
    if(!_textureBackGroundArriere.loadFromFile(IMG_BACKGROUND_BACK))
        imageErreur(IMG_BACKGROUND_BACK);
    else {
        imageTrouvee(IMG_BACKGROUND_BACK);
        _backGroundArriere = new SlidingBackground(_textureBackGroundArriere, LARGEUR_JEU, HAUTEUR_JEU, _model->getVitesseJeu()/2);
    }

    /*** CREATION DE LA BALLE ***/
    if(!_textureBalle.loadFromFile(IMG_BALLE))
        imageErreur(IMG_BALLE);
    else {
        imageTrouvee(IMG_BALLE);
        _balleGraphique = new GraphicElement(_textureBalle, _model->getBalleX(), _model->getBalleY(), 20, 20);

        /*** Redimensionne l'image de la balle ***/
        sf::FloatRect bb = _balleGraphique->getLocalBounds();
        float width_factor = 50/bb.width;
        float height_factor = 50/bb.height;
        _balleGraphique->setScale(width_factor, height_factor);
    }

    /*** CREATION SPRITE OBSTACLE ***/
    if(!_textureObstacle.loadFromFile(IMG_OBSTACLE)) {
        imageErreur(IMG_OBSTACLE);
    }
    else {
        imageTrouvee(IMG_OBSTACLE);
        _obstacleGraphique = new GraphicElement(_textureObstacle, 0, 0, TAILLE_ELEMENTS, TAILLE_ELEMENTS);

        /*** Redimensionne l'image de l'obstacle ***/
        /*
        sf::FloatRect frO = _balleGraphique->getLocalBounds();
        float width_factor_O = 40/frO.width;
        float height_factor_O = 40/frO.height;
        _obstacleGraphique->setScale(width_factor_O, height_factor_O);
        */

    }

    /*** CREATION SPRITE PIECE ***/
    if(!_texturePiece.loadFromFile(IMG_PIECE))
        imageErreur(IMG_BALLE);
    else {
        imageTrouvee(IMG_BALLE);
        _pieceGraphique = new GraphicElement(_texturePiece, 0, 0, TAILLE_ELEMENTS, TAILLE_ELEMENTS);
    }

    /*** CREATION SPRITE MEDIKIT ***/
    if(!_textureMedikit.loadFromFile(IMG_MEDIKIT))
        imageErreur(IMG_MEDIKIT);
    else {
        imageTrouvee(IMG_MEDIKIT);
        _medikitGraphique = new GraphicElement(_textureMedikit, 0, 0, TAILLE_ELEMENTS, TAILLE_ELEMENTS);
    }

    /*** CREATION BARRE DE VIE ***/
    _barreVie.setPosition(sf::Vector2f(POSITION_BARRE_VIE, POSITION_BARRE_VIE));
    _barreVie.setSize(sf::Vector2f(2*_model->getPvBalle(), LARGEUR_BARRE_VIE));
    _barreVie.setFillColor(sf::Color::Green);
    _barreVie.setOutlineThickness(1.f);
    _barreVie.setOutlineColor(sf::Color(0, 0, 0));
    _cadreBarreVie.setPosition(_barreVie.getPosition());
    _cadreBarreVie.setSize(_barreVie.getSize());
    _cadreBarreVie.setFillColor(sf::Color(0, 0, 0));
    _cadreBarreVie.setOutlineThickness(1.f);
    _cadreBarreVie.setOutlineColor(sf::Color(0, 0, 0));


    /*** CREATION TEXTE -> SCORE ***/
    _texteScore.setFont(_font);
    _texteScore.setString("SCORE : " + to_string(_model->getScore()));
    _texteScore.setPosition(_barreVie.getPosition().x, _barreVie.getPosition().y + 20);
    bb = _texteScore.getLocalBounds();
    _texteScore.setScale(100/bb.width, 20/bb.height);
    _texteScore.setColor(sf::Color::Black);

    /* ************ *
    * CREATION MENU *
    * ************ */

    /*** CREATION BOUTONS ***/
    _texteJouer.setFont(_font);
    _texteJouer.setString("JOUER");
    _texteJouer.setPosition(sf::Vector2f(LARGEUR_JEU/3, HAUTEUR_JEU/3));
    bb = _texteJouer.getGlobalBounds();
    _texteJouer.setScale(LARGEUR_BOUTON/bb.width, HAUTEUR_BOUTON/bb.height);
    _texteJouer.setColor(sf::Color::Black);
    _boutonJouer.setPosition(_texteJouer.getPosition());
    _boutonJouer.setSize(sf::Vector2f(LARGEUR_BOUTON, HAUTEUR_BOUTON*2));
    _boutonJouer.setFillColor(sf::Color::Green);
    _boutonJouer.setOutlineThickness(2);
    _boutonJouer.setOutlineColor(sf::Color::Black);

    _texteQuitter.setFont(_font);
    _texteQuitter.setString("QUITTER");
    _texteQuitter.setPosition(sf::Vector2f(_boutonJouer.getPosition().x, _boutonJouer.getPosition().y+_boutonJouer.getGlobalBounds().height + DECALAGE_BOUTONS));
    bb = _texteQuitter.getGlobalBounds();
    _texteQuitter.setScale(LARGEUR_BOUTON/bb.width, HAUTEUR_BOUTON/bb.height);
    _texteQuitter.setColor(sf::Color::Black);
    _boutonQuitter.setPosition(_texteQuitter.getPosition());
    _boutonQuitter.setSize(sf::Vector2f(LARGEUR_BOUTON, HAUTEUR_BOUTON*2));
    _boutonQuitter.setFillColor(sf::Color::Green);
    _boutonQuitter.setOutlineThickness(2);
    _boutonQuitter.setOutlineColor(sf::Color::Black);
}

View::~View(){
    if(_medikitGraphique != NULL)
        delete _medikitGraphique;
    if(_pieceGraphique != NULL)
        delete _pieceGraphique;
    if(_obstacleGraphique != NULL)
        delete _obstacleGraphique;
    if(_balleGraphique != NULL)
        delete _balleGraphique;
    if(_backGroundArriere != NULL)
        delete _backGroundArriere;
    if(_backGroundAvant != NULL)
        delete _backGroundAvant;
    if(_window!= NULL)
        delete _window;
}

void View::draw(){
    _window->clear();

    _backGroundArriere->draw(_window);
    _backGroundAvant->draw(_window);

    if(_dansMenu) {
        _window->draw(_boutonJouer);
        _window->draw(_texteJouer);
        _window->draw(_boutonQuitter);
        _window->draw(_texteQuitter);
    }

    else {
        _balleGraphique->draw(_window);

        _window->draw(_cadreBarreVie);
        _barreVie.setSize(sf::Vector2f(2*_model->getPvBalle(), LARGEUR_BARRE_VIE));
        _window->draw(_barreVie);

        _texteScore.setString("SCORE : " + to_string(_model->getScore()));
        _window->draw(_texteScore);

        for(auto element : _model->recupererElements()) {
            if(element->getType() == "Obstacle") {
                _obstacleGraphique->setPosition(element->getX(), element->getY());
                _obstacleGraphique->draw(_window);
            }
            else if(element->getType() == "Piece") {
                _pieceGraphique->setPosition(element->getX(), element->getY());
                _pieceGraphique->draw(_window);
            }
            else if(element->getType() == "Medikit") {
                _medikitGraphique->setPosition(element->getX(), element->getY());
                _medikitGraphique->draw(_window);
            }
        }
    }

    _window->display();
}

bool View::treatEvents(){
    bool result = false;
    if(_window->isOpen()){
        result = true;

        sf::Event event;
        while (_window->pollEvent(event)) {
            //cout << "Event detected" << endl;
            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                _window->close();
                cout << endl << "Jeu quitté" << endl;
                result = false;
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Left) {
                    _model->deplacerBalle(true);
                }
                else if(event.key.code == sf::Keyboard::Right) {
                    _model->deplacerBalle(false);
                }
                else if(event.key.code == sf::Keyboard::Up) {
                    _model->sautBalle();
                }
            }
            if(event.type == sf::Event::KeyReleased) {
                if(event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right) {
                    _model->stopperBalle();
                }
            }
            else if(event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left && _dansMenu) {
                if(boutonClique(_boutonJouer)) {
                    _dansMenu = false;
                }
                else if (boutonClique(_boutonQuitter)) {
                    _window->close();
                    cout << endl << "Jeu quitté" << endl;
                    result = false;
                }
            }
        }
    }
    if(!_dansMenu)
        _model->nextStep();
    return result;
}

void View::synchronize()
{
    _balleGraphique->setPosition(_model->getBalleX(), _model->getBalleY());
}

bool View::boutonClique(sf::RectangleShape bouton) const
{
    int sourisX = sf::Mouse::getPosition().x;
    int sourisY = sf::Mouse::getPosition().y;
    int boutonX = bouton.getPosition().x;
    int boutonY = bouton.getPosition().y;
    int boutonW = bouton.getGlobalBounds().width;
    int boutonH = bouton.getGlobalBounds().height;

    cout << "SOURIS (" << sourisX << ", " << sourisY << ")" << endl << "BOUTON (" << boutonX << " ," << boutonY << ", " << boutonW << ", " << boutonH << ")" << endl;

    if(sourisX > boutonX && sourisX < boutonX+boutonW && sourisY > boutonY && sourisY < boutonY+boutonH)
        return true;
    return false;
}

void View::imageTrouvee(string chemin)
{
    cout << chemin << " -> chargée" << endl;
}

void View::policeErreur(string chemin)
{
    cerr << "ERREUR lors du chargement de la police -> " << chemin << endl;
}

void View::policeTrouvee(string chemin)
{
    cout << chemin << " -> chargée" << endl;
}

void View::imageErreur(string chemin)
{
    cerr << "ERREUR lors du chargement de l'image -> " << chemin << endl;
}
