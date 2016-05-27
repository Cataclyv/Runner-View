#include "View.h"

using namespace std;

View::View(Model *model) : _w{LARGEUR_JEU}, _h{HAUTEUR_JEU}, _model{model}, _dansMenu{false}, _finJeu{false}, _reinit{false}, _dansIntro{true}
{
    _window = new sf::RenderWindow(sf::VideoMode(_w, _h, 32), "Runner", sf::Style::Close);
    _window->setKeyRepeatEnabled(true);

    _tempsFin = _horloge.restart();
    _tempsScore = _horloge.restart();
    _tempsIntro = _horloge.restart();

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
        _balleGraphique->resize(_model->getBalleW(), _model->getBalleH());
    }

    /*** CREATION SPRITE ELEMENTS ***/
    if(!_textureObstacleBase.loadFromFile(IMG_OBSTACLE_BASE)) {
        imageErreur(IMG_OBSTACLE_BASE);
    }
    else {
        imageTrouvee(IMG_OBSTACLE_BASE);
    }

    if(!_textureObstacleAir.loadFromFile(IMG_OBSTACLE_AIR)) {
        imageErreur(IMG_OBSTACLE_AIR);
    }
    else {
        imageTrouvee(IMG_OBSTACLE_AIR);
    }

    if(!_textureObstacleGrand.loadFromFile(IMG_OBSTACLE_GRAND)) {
        imageErreur(IMG_OBSTACLE_GRAND);
    }
    else {
        imageTrouvee(IMG_OBSTACLE_GRAND);
    }

    if(!_texturePiece.loadFromFile(IMG_PIECE))
        imageErreur(IMG_BALLE);
    else {
        imageTrouvee(IMG_BALLE);
    }

    if(!_textureMedikit.loadFromFile(IMG_MEDIKIT))
        imageErreur(IMG_MEDIKIT);
    else {
        imageTrouvee(IMG_MEDIKIT);
    }
    // INITIALISATION //
    _elementGraphique = new GraphicElement(_textureObstacleBase, 0, 0, TAILLE_ELEMENTS, TAILLE_ELEMENTS);

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

    /*** CREATION TEXTE -> GAME OVER ***/
    _texteFin.setFont(_font);
    _texteFin.setString("GAME OVER \nRETOUR AU MENU DANS 5...");
    _texteFin.setPosition(sf::Vector2f(250, 250));
    _texteFin.setColor(sf::Color::Black);

    /* ************ *
    * CREATION MENU *
    * ************ */

    /*** LOGO IUT ***/
    if(!_textureLogo.loadFromFile(IMG_IUT)) {
        imageErreur(IMG_IUT);
    }
    else {
        _logoGraphique = new GraphicElement(_textureLogo, 0, 0, 10, 10);
    }

    /*** TITRE DU JEU ***/
    _titre.setFont(_font);
    _titre.setString("RUNNER");
    _titre.setPosition(_logoGraphique->getPosition().x+_logoGraphique->getTextureRect().width+150, 5);
    bb = _titre.getLocalBounds();
    _titre.setScale(LARGEUR_BOUTON/bb.width, HAUTEUR_BOUTON/bb.height);
    _titre.setColor(sf::Color::Black);

    /*** CREATION BOUTONS ***/
    _texteJouer.setFont(_font);
    _texteJouer.setString("JOUER");
    _texteJouer.setPosition(sf::Vector2f(_titre.getPosition().x, HAUTEUR_JEU/3));
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

    /*** TEXTE INTRODUCTION ***/
    _texteIntro.setFont(_font);
    _texteIntro.setString("Jules Despret et Romain Cremery presentent...");
    _texteIntro.setPosition(LARGEUR_JEU/11, HAUTEUR_JEU/2);
}

View::~View(){
    if(_logoGraphique != NULL)
        delete _logoGraphique;
    if(_elementGraphique != NULL)
        delete _elementGraphique;
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

    if(_dansIntro) {
        _logoGraphique->draw(_window);
        _window->draw(_texteIntro);
        _tempsIntro += _horloge.getElapsedTime();
        if(_tempsIntro.asSeconds() > 50) {
            _dansMenu = true;
            _dansIntro = false;
        }
    }

    else {
        _backGroundArriere->draw(_window);
        _backGroundAvant->draw(_window);

        if(_dansMenu) {
            _logoGraphique->draw(_window);
            _window->draw(_boutonJouer);
            _window->draw(_texteJouer);
            _window->draw(_boutonQuitter);
            _window->draw(_texteQuitter);
            _window->draw(_titre);
        }

        else if(_finJeu) {
            int temps_restant = TEMPS_GAME_OVER - _tempsFin.asSeconds();
            _texteFin.setString("           GAME OVER \nRETOUR AU MENU DANS " + to_string(temps_restant) + "...");
            _window->draw(_texteFin);

            _tempsFin = _horloge.getElapsedTime();

            if(_tempsFin.asSeconds() > TEMPS_GAME_OVER-1) {
                _finJeu = false;
                _dansMenu = true;
            }
        }

        else {
            _balleGraphique->draw(_window);

            _window->draw(_cadreBarreVie);
            _barreVie.setSize(sf::Vector2f(2*_model->getPvBalle(), LARGEUR_BARRE_VIE));
            _window->draw(_barreVie);

            _texteScore.setString("SCORE : " + to_string(_model->getScore()));
            _window->draw(_texteScore);

            for(auto element : _model->recupererElements()) {
                if(element->getType() == OBSTACLE_BASE) {
                    _elementGraphique->setTexture(_textureObstacleBase);
                }
                else if(element->getType() == OBSTACLE_AIR) {
                    _elementGraphique->setTexture(_textureObstacleAir);;
                }
                else if(element->getType() == OBSTACLE_GRAND) {
                    _elementGraphique->setTexture(_textureObstacleGrand);
                }
                else if(element->getType() == PIECE) {
                    _elementGraphique->setTexture(_texturePiece);
                }
                else if(element->getType() == MEDIKIT) {
                    _elementGraphique->setTexture(_textureMedikit);
                }
                _elementGraphique->resize(element->getW(), element->getH());
                _elementGraphique->setPosition(element->getX(), element->getY());
                _elementGraphique->draw(_window);
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
            else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && _dansMenu) {
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
    if(!_dansMenu && !_finJeu) {
        _reinit = false;
        bool jeu = _model->nextStep();
        synchronize();
        if(!jeu) {
            _finJeu = true;
            if(!_reinit) {
                _model = new Model();
                _tempsFin = _horloge.restart();
            }
        }
    }
    return result;
}

void View::synchronize()
{
    _balleGraphique->setPosition(_model->getBalleX(), _model->getBalleY());
    _tempsScore += _horloge.getElapsedTime();
    if(_tempsScore.asSeconds() > 10) {
        _model->ajouterTempsAuScore();
        _tempsScore = _horloge.restart();
    }
}

bool View::boutonClique(sf::RectangleShape bouton) const
{
    int sourisX = sf::Mouse::getPosition().x - _window->getPosition().x;
    int sourisY = sf::Mouse::getPosition().y - _window->getPosition().y;
    int boutonX = bouton.getPosition().x;
    int boutonY = bouton.getPosition().y;
    int boutonW = bouton.getGlobalBounds().width;
    int boutonH = bouton.getGlobalBounds().height;

    if(VERBOSE)
        cout << "SOURIS (" << sourisX << ", " << sourisY << ")" << endl << "BOUTON (" << boutonX << " ," << boutonY << ", " << boutonW << ", " << boutonH << ")" << endl;

    if(sourisX > boutonX && sourisX < boutonX+boutonW && sourisY > boutonY && sourisY < boutonY+boutonH)
        return true;
    return false;
}

void View::imageTrouvee(string chemin)
{
    if(VERBOSE)
        cout << chemin << " -> chargée" << endl;
}

void View::policeErreur(string chemin)
{
    cerr << "ERREUR lors du chargement de la police -> " << chemin << endl;
}

void View::policeTrouvee(string chemin)
{
    if(VERBOSE)
        cout << chemin << " -> chargée" << endl;
}

void View::imageErreur(string chemin)
{
    cerr << "ERREUR lors du chargement de l'image -> " << chemin << endl;
}
