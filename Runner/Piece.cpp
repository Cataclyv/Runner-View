#include "Piece.h"

Piece::Piece(int x) : Bonus(x, VAL_PIECE)
{
    std::cout << " -> Piece" << std::endl;
}

std::string Piece::getType() const {
    return "Piece";
}
