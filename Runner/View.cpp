#include "View.h"

using namespace std;

View::View() : _w{VIEW_WIDTH}, _h{VIEW_HEIGHT}
{
    _window = new sf::RenderWindow(sf::VideoMode(_w, _h, 32), "Runner", sf::Style::Close);

    sf::Texture backGroundFrontTexture;
    if(!backGroundFrontTexture.loadFromFile(IMG_BACKGROUND_FRONT))
        std::cerr << "ERREUR lors du chargement de l'image -> " << IMG_BACKGROUND_FRONT << std::endl;
    else {
        _backGroundAvant = new SlidingBackground(backGroundFrontTexture, VIEW_WIDTH, VIEW_HEIGHT, 1);
        _backGroundAvant->setTexture(backGroundFrontTexture);
    }

    sf::Texture backGroundBackTexture;

    /*** CREATION DE LA BALLE ***/
    sf::Texture balleTexture;

    if(!balleTexture.loadFromFile(IMG_BALLE))
        std::cerr << "ERREUR lors du chargement de l'image -> " << IMG_BALLE << std::endl;

    else {
        g_balle = new GraphicElement(balleTexture, 10, 10, 20, 20);

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
