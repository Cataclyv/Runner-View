#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include "Balle.h"

class Obstacle : public MovableElement
{
private:
    /**
     * @brief _type
     * Le type d'obstacle ; détermine son apparence dans la vue
     */
    std::string _type;
public:
    Obstacle(int x, int y, int h, int w, int dx, int dy, std::string type);

    /**
     * @brief getType
     * @return
     */
    std::string getType() const;
    /**
     * @brief verbose
     * Affiche les informations de l'obstacle dans le terminal
     */
    void verbose() const;
};

#endif // OBSTACLE_H
