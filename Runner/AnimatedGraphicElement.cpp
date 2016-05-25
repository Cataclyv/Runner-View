#include "AnimatedGraphicElement.h"
#include <SFML/Graphics.hpp>

AnimatedGraphicElement::AnimatedGraphicElement(const std::vector<sf::IntRect>& clipRects, sf::Texture &image, int x, int y, int w, int h)
    :GraphicElement(image, x, y, w, h)
{
    m_clipRects = clipRects;
    m_clipRect = 0;
    m_nb_etapes = 8;
    m_etape = 0;
    setTextureRect(m_clipRects[m_clipRect]);
}

AnimatedGraphicElement::AnimatedGraphicElement(const AnimatedGraphicElement &copie)
    :GraphicElement(copie)
{
    m_clipRects = copie.m_clipRects;
    m_clipRect = copie.m_clipRect;
    m_nb_etapes = copie.m_nb_etapes;
    m_etape = copie.m_etape;
    setTextureRect(m_clipRects[m_clipRect]);
}

void AnimatedGraphicElement::draw(sf::RenderWindow *window)
{
    m_etape++;
    if(m_etape>m_nb_etapes)
    {
        m_etape = 0;
        m_clipRect = m_clipRect % m_clipRects.size()+1;
        setTextureRect(m_clipRects[m_clipRect-1]);
    }
    window->draw(*this);
}
