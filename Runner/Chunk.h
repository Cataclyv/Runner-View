#ifndef CHUNK_H
#define CHUNK_H

#include "Obstacle.h"
#include "Piece.h"
#include "Medikit.h"
#include "Vol.h"
#include "Invincibilite.h"
#include <vector>
#include <string>

class Chunk : public MovableElement
{
private :
    std::vector<MovableElement*> _conteneur; // soit Bonus soit Obstacle
public:
    Chunk(int x, int type);    // 1-> bonus, 2->obstacle, autre->rien
    void move();
    bool collision(Balle *_balle) const; // Détermine s'il y a collision entre la balle et un élément
    std::string objetTouche() const;
};

#endif // CHUNK_H
