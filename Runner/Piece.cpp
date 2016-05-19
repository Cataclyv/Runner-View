#include "Piece.h"

Piece::Piece(int x, int vitesse) : Bonus(x, vitesse, VAL_PIECE)
{
    std::cout << " -> Piece" << std::endl;
}

std::string Piece::getType() const {
    return "Piece";
}
