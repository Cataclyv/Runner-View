#include "GraphicElement.h"

GraphicElement::GraphicElement(sf::Texture &image, int x, int y, int w, int h)
    : Sprite{image}, _w{w}, _h{h}
{
    setPosition(x, y);
}

void GraphicElement::draw(sf::RenderWindow *window) {
    window->draw(*this);
}
