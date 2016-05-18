#include "SlidingBackground.h"

SlidingBackground::SlidingBackground(sf::Texture &image, int w, int h, unsigned int vitesse)
    : _left{image, 0, 0, w, h}, _right{image, w, 0, w, h}, _w{w}, _h{h}, _vitesse{vitesse}
{
    /*** Redimensionne l'image à gauche ***/
    sf::FloatRect frG = _left.getLocalBounds();
    float width_factor_G = 800/frG.width;
    float height_factor_G = 600/frG.height;
    _left.setScale(width_factor_G, height_factor_G);

    /*** Redimensionne l'image à droite ***/
    sf::FloatRect frD = _right.getLocalBounds();
    float width_factor_D = 800/frD.width;
    float height_factor_D = 600/frD.height;
    _right.setScale(width_factor_D, height_factor_D);
}

void SlidingBackground::draw(sf::RenderWindow *window) {
    _left.setPosition(_left.getPosition().x-_vitesse, _left.getPosition().y);
    _right.setPosition(_right.getPosition().x-_vitesse, _right.getPosition().y);
    /*** Réinitialisation si LEFT sort intégralement de l'écran ***/
    if(_left.getPosition().x < -_left.getW()) {
        _left.setPosition(0, 0);
        _right.setPosition(_left.getW(), 0);
    }
    window->draw(_left);
    window->draw(_right);
}

