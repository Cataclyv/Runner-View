#include "ecranintroduction.h"

ecranIntroduction::ecranIntroduction()
{
    if (!m_intro1.loadFromFile(IMG_INTRO1))
        std::cout << "ERROR when loading image file: " << IMG_INTRO1 << std::endl;
    else {
        m_intro1.setSmooth(true);
        GraphicElement tmp{m_intro1, 115,150,1000,298};
        m_img1 = tmp;
        m_img1.setTransparency(true);
    }

    if (!m_intro2.loadFromFile(IMG_INTRO2))
        std::cout << "ERROR when loading image file: " << IMG_INTRO2 << std::endl;
    else {
        m_intro2.setSmooth(true);
        GraphicElement tmp{m_intro2, 0,65,1200,500};
        m_img2 = tmp;
        m_img2.setTransparency(true);
    }
}

void ecranIntroduction::draw(sf::RenderWindow *window)
{
    if(m_cpt < 300)
    {
        window->draw(m_intro1);
        m_cpt+=2;
    }
    else
    {
        window->draw(m_intro2);
        m_cpt+=2;
    }
}

bool ecranIntroduction::allerMenu()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || m_cpt>=600)
    {
        return true;
    }
}
