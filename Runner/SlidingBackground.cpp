#include "SlidingBackground.h"

SlidingBackground::SlidingBackground(sf::Texture &image, int w, int h, unsigned int vitesse)
    : _gauche{image, 0, 0, w, h}, _droite{image, w, 0, w, h}, _w{w}, _h{h}, _vitesse{vitesse}
{
    /*** Redimensionne l'image à gauche ***/
    sf::FloatRect frG = _gauche.getLocalBounds();
    float width_factor_G = 800/frG.width;
    float height_factor_G = 600/frG.height;
    _gauche.setScale(width_factor_G, height_factor_G);

    /*** Redimensionne l'image à droite ***/
    sf::FloatRect frD = _droite.getLocalBounds();
    float width_factor_D = 800/frD.width;
    float height_factor_D = 600/frD.height;
    _droite.setScale(width_factor_D, height_factor_D);
}

void SlidingBackground::draw(sf::RenderWindow *window) {
    _gauche.setPosition(_gauche.getPosition().x-_vitesse, _gauche.getPosition().y);
    _droite.setPosition(_droite.getPosition().x-_vitesse, _droite.getPosition().y);
    /*** Réinitialisation si LEFT sort intégralement de l'écran ***/
    if(_gauche.getPosition().x < -_gauche.getW()) {
        _gauche.setPosition(0, 0);
        _droite.setPosition(_gauche.getW(), 0);
    }
    window->draw(_gauche);
    window->draw(_droite);
}

