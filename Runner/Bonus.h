#ifndef BONUS_H
#define BONUS_H

#include <iostream>
#include <string>
#include "MovableElement.h"

const int TAILLE = 40;

class Bonus : public MovableElement
{
private:
    /**
     * @brief _type
     * Détermine le type de bonus ; utilisé pour appliquer différents effets sur la balle dans le modèle
     */
    std::string _type;
public:
    /**
     * @brief Bonus
     * @param x
     * @param taille
     * @param vitesse
     * @param type
     */
    Bonus(int x, int taille, int vitesse, std::string type);

    /**
     * @brief move
     * Déplace le bonus en fonction de son dx et de son dy
     */
    void move();

    /**
     * @brief getType
     * @return
     * Retourne le type du bonus pour en déterminer l'effet et l'apparence
     */
    virtual std::string getType() const;
    /**
     * @brief verbose
     * Affiche les informations du bonus dans le terminal
     */
    virtual void verbose() const;
};

#endif // BONUS_H
