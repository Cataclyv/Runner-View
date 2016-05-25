#ifndef ECRANINTRODUCTION_H
#define ECRANINTRODUCTION_H

#include "GraphicElement.h"

const std::string INTRO_IMG1 = "";
const std::string INTRO_IMG2 = "";

class ecranIntroduction
{
private:
    sf::Texture m_intro1;
    sf::Texture m_intro2;
    GraphicElement m_img1;
    GraphicElement m_img2;
public:
    ecranIntroduction();
    void draw(sf::RenderWindow *window);
};

#endif // ECRANINTRODUCTION_H
