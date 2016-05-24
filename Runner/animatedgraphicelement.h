#ifndef ANIMATEDGRAPHICELEMENT_H
#define ANIMATEDGRAPHICELEMENT_H

#include <GraphicElement.h>
#include <SFML/Graphics.hpp>

class AnimatedGraphicElement : public GraphicElement
{
private:
    std::vector<sf::IntRect> m_clipRects;
    int m_nb_etapes;
    int m_etape;
    int m_clipRect;
public:
    AnimatedGraphicElement(const std::vector<sf::IntRect>& clipRects, sf::Texture &image, int x, int y, int w, int h);
    AnimatedGraphicElement(const AnimatedGraphicElement& copy);
    void draw(sf::RenderWindow *window);
};

#endif // ANIMATEDGRAPHICELEMENT_H
