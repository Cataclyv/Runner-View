#ifndef PIECE_H
#define PIECE_H

#include "Bonus.h"
#include "Balle.h"

class Piece : public Bonus
{
private:

public:
    Piece(int x, int vitesse);

    virtual std::string getType() const;
};

#endif // PIECE_H
