#ifndef CHUNK_H
#define CHUNK_H

#include "Obstacle.h"
#include "Piece.h"
#include "Medikit.h"
#include "Vol.h"
#include "Invincibilite.h"
#include <vector>
#include <string>

const int ESPACE = 20;

class Chunk : public MovableElement
{
private :
    std::vector<MovableElement*> _conteneur; // soit Bonus soit Obstacle
public:
    Chunk(int x, int getType);    // 1-> bonus, 2->obstacle, autre->rien
    virtual ~Chunk();
    void move();
    bool collision(Balle *_balle) const; // Détermine s'il y a collision entre la balle et un élément
    std::string objetTouche() const;
    int taille() const;
    std::string getType(int index) const;
};

#endif // CHUNK_H
