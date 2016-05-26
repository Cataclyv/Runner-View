#include "GraphicElement.h"

GraphicElement::GraphicElement(sf::Texture &image, int x, int y, int w, int h)
    : Sprite{image}, _w{w}, _h{h}
{
    setPosition(x, y);
}

void GraphicElement::draw(sf::RenderWindow *window) {
    window->draw(*this);
}

void GraphicElement::resize(int nouvelleLargeur, int nouvelleHauteur)
{
    sf::FloatRect bb = this->getLocalBounds();
    this->setScale(nouvelleLargeur/bb.width, nouvelleHauteur/bb.height);
}

int GraphicElement::getW() const {
    return _w;
}

int GraphicElement::getH() const {
    return _h;
}

