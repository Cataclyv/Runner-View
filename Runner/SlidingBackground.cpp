#include "SlidingBackground.h"

SlidingBackground::SlidingBackground(sf::Texture &image, int w, int h, unsigned int vitesse)
    : _w{w}, _h{h}, _vitesse{vitesse}
{
    _left = new GraphicElement(image, 0, 0, w, h);
    _right = new GraphicElement(image, w, 0, w, h);
}

void SlidingBackground::draw(sf::RenderWindow &window) {

}
