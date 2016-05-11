#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <SFML/Graphics.hpp>

class GraphicElement : public sf::Sprite
{
private :
    int _w, _h;
public:
    GraphicElement(sf::Texture &image, int x, int y, int w, int h);
    void draw(sf::RenderWindow *window);
};

#endif // GRAPHICELEMENT_H
