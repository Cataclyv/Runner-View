#ifndef BALLE_H
#define BALLE_H

#include "MovableElement.h"

const int W_BALLE = 50;
const int H_BALLE = 50;
const int PV_MAX = 100;

class Balle : public MovableElement
{
private :
    /**
     * @brief _pv
     * La quantité de points de vie de la balle
     */
    int _pv;
    /**
     * @brief _enSaut
     * Détermine si la balle est en phase de saut
     */
    bool _enSaut;
    /**
     * @brief _enChute
     * Détermine si la balle est en phase de chute ; utilisé pendant la phase de saut
     */
    bool _enChute;
public:
    /**
     * @brief Balle
     * @param hauteur
     */
    Balle(int hauteur);

    virtual ~Balle() = default;

    /**
     * @brief move
     * Déplace la balle selon son dx et sont dy
     */
    void move() override;

    /**
     * @brief getPv
     * @return
     * Retourne la quantité de points de vie de la balle
     */
    int getPv() const;
    /**
     * @brief getEnSaut
     * @return
     * Retourne si la balle est en phase de saut
     */
    bool getEnSaut() const;
    /**
     * @brief getEnChute
     * @return
     * Retourne si la balle est en phase de chute
     */
    bool getEnChute() const;

    /**
     * @brief setDx
     * @param dx
     * Modifie le dx de la balle
     */
    void setDx(int dx);
    /**
     * @brief setPv
     * @param pv
     * Modifie les points de vie de la balle
     */
    void setPv(int pv);
    /**
     * @brief setEnSaut
     * @param saut
     * Permet d'entrer ou de sortir de la phase de saut
     */
    void setEnSaut(bool saut);
    /**
     * @brief setEnChute
     * @param chute
     * Permet d'entrer ou de sortir de la phase de chute
     */
    void setEnChute(bool chute);
};

#endif // BALLE_H
