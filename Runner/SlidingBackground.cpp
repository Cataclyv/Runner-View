#include "SlidingBackground.h"

SlidingBackground::SlidingBackground(sf::Texture &image, int w, int h, unsigned int vitesse)
    : _w{w}, _h{h}, _vitesse{vitesse}
{
    _left = new GraphicElement(image, 0, 0, w, h);
    _right = new GraphicElement(image, w, 0, w, h);
}

void SlidingBackground::setTexture(sf::Texture &image)
{
    _left->setTexture(image);
    _right->setTexture(image);
}

void SlidingBackground::draw(sf::RenderWindow &window) {
    _left->setPosition(_left->getPosition().x-_vitesse, _left->getPosition().y);
    if(_left->getPosition().x < 0-_left->getW()) {
        _left->setPosition(_right->getPosition());
        _right->setPosition(_left->getPosition().x + _left->getW(), _left->getPosition().y);
    }
    _right->setPosition(_right->getPosition().x-_vitesse, _right->getPosition().y);
    window.draw(*this->_left);
    window.draw(*this->_right);
}

