#include "Score.h"

Score::Score()
    : _nbPieces{0}, _nbBonus{0}, _tempsPasse{0}, _pseudo{"Joueur"}
{
}

int Score::score() {
    return _tempsPasse
            + _nbPieces * 10
            + _nbBonus * 50;
}

void Score::plusPiece() {
    _nbPieces++;
}

void Score::plusBonus() {
    _nbBonus++;
}

void Score::plusTemps() {
    _tempsPasse++;
}

std::string Score::getPseudo() {
    return _pseudo;
}

void Score::setPseudo(std::string pseudo) {
    _pseudo = pseudo;
}
