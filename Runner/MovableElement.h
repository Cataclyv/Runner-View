#ifndef MOVABLEELEMENT_H
#define MOVABLEELEMENT_H

#include <string>
#include <iostream>

class MovableElement
{
protected :
    /**
     * @brief _id
     * Identifiant de l'élément
     */
    int _id;
    /**
     * @brief _nbME
     * Nombre d'éléments utilisés dans le jeu ; utilisé pour attribuer des identifiants
     */
    static int _nbME;
    /**
     * @brief _x
     * Coordonnée X de l'élément
     */
    int _x;
    /**
     * @brief _y
     * Coordonnée Y de l'élément
     */
    int _y;
    /**
     * @brief _w
     * Largeur de l'élément
     */
    int _w;
    /**
     * @brief _h
     * Hauteur de l'élément
     */
    int _h;
    /**
     * @brief _dx
     * Quantité de déplacement horizontal de l'élément
     */
    int _dx;
    /**
     * @brief _dy
     * Quantité de déplacement vertical de l'élément
     */
    int _dy;

public:
    /**
     * @brief MovableElement
     * @param x
     * @param y
     * @param w
     * @param h
     * @param dx
     * @param dy
     */
    MovableElement(int x, int y, int w, int h, int dx, int dy);

    virtual ~MovableElement() = default;
    /**
     * @brief move
     * Déplace l'élément selon son dx et son dy
     */
    virtual void move();

    /**
     * @brief getX
     * @return
     */
    int getX() const;
    /**
     * @brief getY
     * @return
     */
    int getY() const;
    /**
     * @brief getDx
     * @return
     */
    int getDx() const;
    /**
     * @brief getDy
     * @return
     */
    int getDy() const;
    /**
     * @brief getH
     * @return
     */
    int getH() const;
    /**
     * @brief getW
     * @return
     */
    int getW() const;

    /**
     * @brief setX
     * @param x
     */
    void setX(int x);
    /**
     * @brief setY
     * @param y
     */
    void setY(int y);
    /**
     * @brief setDx
     * @param dx
     */
    void setDx(int dx);
    /**
     * @brief setDy
     * @param dy
     */
    void setDy(int dy);

    /**
     * @brief enJeu
     * @return
     * Détermine si l'élément courant est intégralement sorti de l'espace de jeu ou non
     */
    bool enJeu() const;
    /**
     * @brief collision
     * @param element
     * @return
     * Retourne si une collision est détectée entre l'élément courant et un autre élément
     */
    bool collision(MovableElement *element) const;

    /**
     * @brief getType
     * @return
     */
    virtual std::string getType() const;
    /**
     * @brief verbose
     */
    virtual void verbose() const;
};

#endif // MOVABLEELEMENT_H
