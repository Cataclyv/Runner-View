#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <SFML/Graphics.hpp>

class GraphicElement : public sf::Sprite
{
private :
    /**
     * @brief _w
     * La largeur de l'élément graphique
     */
    int _w;
    /**
     * @brief _h
     * La hauteur de l'élément graphique
     */
    int _h;
public:
    GraphicElement(sf::Texture &image, int x, int y, int w, int h);
    /**
     * @brief draw
     * @param window
     * Dessine l'élément graphique courant dans la fenêtre en paramètre
     */
    void draw(sf::RenderWindow *window);
    /**
     * @brief resize
     * @param nouvelleLargeur
     * @param nouvelleHauteur
     * Redimensionne l'élément graphique courant selon une nouvelle largeur et une nouvelle hauteur
     */
    void resize(int nouvelleLargeur, int nouvelleHauteur);

    int getW() const;
    int getH() const;
};

#endif // GRAPHICELEMENT_H
