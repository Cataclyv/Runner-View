#ifndef SCORE_H
#define SCORE_H

#include <string>

class Score
{
private :
    /**
     * @brief _nbPieces
     * Nombre de pièces ramassées par le joueur
     */
    int _nbPieces;
    /**
     * @brief _nbBonus
     * Nombre de bonus ramassés par le joueur
     */
    int _nbBonus;
    /**
     * @brief _tempsPasse
     * Temps passé dans la partie courante ; permet au score de s'incrémenter avec le temps
     */
    int _tempsPasse;
    /**
     * @brief _pseudo
     * Pseudonyme du joueur, pour l'associer à son score
     */
    std::string _pseudo;
public:
    /**
     * @brief Score
     */
    Score();

    /**
     * @brief score
     * @return
     * Calcule et retourne le score total du joueur
     */
    int score();

    /**
     * @brief plusPiece
     * Incrémente le nombre de pièces
     */
    void plusPiece();
    /**
     * @brief plusBonus
     * Incrémente le nombre de bonus
     */
    void plusBonus();
    /**
     * @brief plusTemps
     * Incrémente le temps passé
     */
    void plusTemps();

    /**
     * @brief getPseudo
     * @return
     */
    std::string getPseudo();
    /**
     * @brief setPseudo
     * @param pseudo
     */
    void setPseudo(std::string pseudo);
};

#endif // SCORE_H
