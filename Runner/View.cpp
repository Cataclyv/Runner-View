#include "View.h"

using namespace std;

View::View() : _w{VIEW_WIDTH}, _h{VIEW_HEIGHT}
{
    _window = new sf::RenderWindow(sf::VideoMode(_w, _h, 32), "Runner", sf::Style::Close);

    /*** SLIDINGBACKGROUND AVANT ***/
    sf::Texture backGroundFrontTexture;
    if(!backGroundFrontTexture.loadFromFile(IMG_BACKGROUND_FRONT))
        erreurImage(IMG_BACKGROUND_FRONT);
    else {
        imageTrouvee(IMG_BACKGROUND_FRONT);
        _backGroundAvant = new SlidingBackground(backGroundFrontTexture, VIEW_WIDTH, VIEW_HEIGHT, 1);
        _backGroundAvant->setTexture(backGroundFrontTexture);
    }

    /*** SLIDINGBACKGROUND ARRIERE ***/
    sf::Texture backGroundBackTexture;
    if(!backGroundBackTexture.loadFromFile(IMG_BACKGROUND_BACK))
        erreurImage(IMG_BACKGROUND_BACK);
    else {
        imageTrouvee(IMG_BACKGROUND_BACK);
        _backGroundAvant = new SlidingBackground(backGroundBackTexture, VIEW_WIDTH, VIEW_HEIGHT, 1);
        _backGroundAvant->setTexture(backGroundBackTexture);
    }

    /*** CREATION DE LA BALLE ***/
    sf::Texture balleTexture;

    if(!balleTexture.loadFromFile(IMG_BALLE))
        erreurImage(IMG_BALLE);

    else {
        imageTrouvee(IMG_BALLE);

        int x = 15;
        int y = 15;
        _model->positionBalle(x, y);
        cout << x << " / " << y << endl;

        g_balle = new GraphicElement(balleTexture, x, y, 20, 20);

        /*\ Redimensionne l'image de la balle \*/
        sf::FloatRect bb = g_balle->getLocalBounds();
        float width_factor = 100/bb.width;
        float height_factor = 100/bb.height;
        g_balle->setScale(width_factor, height_factor);
    }
}

View::~View(){
    if(g_balle != NULL)
        delete g_balle;
    for(auto element : _movableToGraphic)
        delete element.second;
    if(_window!= NULL)
        delete _window;
}

void View::setModel(Model * model){
    _model = model;
}

void View::draw(){
    _window->clear();

    g_balle->draw(_window);

    for(auto element : _movableToGraphic) {
        element.second->draw(_window);
    }

    _window->display();
}

bool View::treatEvents(){
    bool result = false;
    if(_window->isOpen()){
        result = true;

        sf::Event event;
        while (_window->pollEvent(event)) {
            cout << "Event detected" << endl;

            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                _window->close();
                result = false;
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Left) {

                }
                else if(event.key.code == sf::Keyboard::Right) {

                }
            }
        }
    }
    return result;
}

void View::synchronize()
{
    int x, y;
    _model->positionBalle(x, y);
    g_balle->setPosition(x, y);
    for(auto element : _movableToGraphic) {
        element.second->setPosition(element.first->getX(), element.first->getY());
    }
}

void View::imageTrouvee(string chemin)
{
    cerr << chemin << " -> chargée" << endl;
}

void View::erreurImage(string chemin)
{
    cerr << "ERREUR lors du chargement de l'image -> " << chemin << std::endl;
}
