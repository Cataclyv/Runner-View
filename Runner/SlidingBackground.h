#ifndef SLIDINGBACKGROUND_H
#define SLIDINGBACKGROUND_H

#include "GraphicElement.h"

class SlidingBackground
{
private :
    /**
     * @brief _gauche
     * Image à gauche
     */
    GraphicElement _gauche;
    /**
     * @brief _droite
     * Image à droite
     */
    GraphicElement _droite;
    /**
     * @brief _w
     * Largeur du background
     */
    int _w;
    /**
     * @brief _h
     * Hauteur du background
     */
    int _h;
    /**
     * @brief _vitesse
     * Vitesse de déplacement du background
     */
    unsigned int _vitesse;
public:
    /**
     * @brief SlidingBackground
     * @param image
     * @param w
     * @param h
     * @param vitesse
     */
    SlidingBackground(sf::Texture &image, int w, int h, unsigned int vitesse);
    ~SlidingBackground() = default;
    /**
     * @brief draw
     * @param window
     * Dessine l'image à gauche et l'image à droite du background, et les recadre si l'image à gauche sort complètement de l'espace de jeu
     */
    void draw(sf::RenderWindow *window);
};

#endif // SLIDINGBACKGROUND_H
