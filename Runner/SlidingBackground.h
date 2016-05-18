#ifndef SLIDINGBACKGROUND_H
#define SLIDINGBACKGROUND_H

#include "GraphicElement.h"

class SlidingBackground
{
private :
    GraphicElement _left, _right;
    int _w, _h;
    unsigned int _vitesse;
public:
    SlidingBackground(sf::Texture &image, int w, int h, unsigned int vitesse);
    void draw(sf::RenderWindow *window);
};

#endif // SLIDINGBACKGROUND_H
