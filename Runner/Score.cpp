#include "Score.h"

Score::Score()
    : _nbPieces{0}, _nbBonus{0}, _nbChunks{0}, _pseudo{"Joueur"}
{
}

int Score::score() {
    return _nbPieces * 10
            + _nbBonus * 50
            + _nbChunks * 100;
}

void Score::plusPiece() {
    _nbPieces++;
}

void Score::plusBonus() {
    _nbBonus++;
}

void Score::plusChunk() {
    _nbChunks++;
}

std::string Score::getPseudo() {
    return _pseudo;
}

void Score::setPseudo(std::string pseudo) {
    _pseudo = pseudo;
}
