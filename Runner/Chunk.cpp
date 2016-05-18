#include "Chunk.h"
#include <cstdlib>

Chunk::Chunk(int x, int type)
    : MovableElement{x, 10, 100, 100, -1, 0}
{
    _conteneur.resize(5);
    for(unsigned int j=0 ; j<_conteneur.size() ; j++)
        _conteneur[j] = nullptr;
    srand(time(NULL));

    switch(type)
    {

    case 1 : {  // Insertion et déterminisation des bonus
        int emplacement_bonus = rand()%5;
        int type_bonus = rand()%3;
        Bonus *_bonus;

        switch(type_bonus)
        {
        case 0 :
            _bonus = new Medikit(_x+TAILLE*emplacement_bonus);
            break;
        case 1 :
            _bonus = new Vol(_x+TAILLE*emplacement_bonus);
            break;
        case 2 :
            _bonus = new Invincibilite(_x+TAILLE*emplacement_bonus);
            break;
        }
        _conteneur[emplacement_bonus] = _bonus;
        for(unsigned int i=0 ; i<_conteneur.size() ; i++)
        {
            if(_conteneur[i] == nullptr)
                _conteneur[i] = new Piece(_x+TAILLE*i);
        }
         } break;

    case 2 : {  // Insertion et déterminisation des obstacles
        int type_o = 0;
        for(unsigned int i=0; i<_conteneur.size() ; i++)
        {
            type_o = rand()%2;
            switch(type_o)
            {
            case 0 :
                if(_conteneur[i] == nullptr)
                {
                    _conteneur[i] = new Obstacle(_x+TAILLE*i, _y, TAILLE, TAILLE, -1, 0);
                }
                break;
            case 1 :
                if(_conteneur[i] == nullptr)
                {
                    _conteneur[i] = new Obstacle(_x+TAILLE*i, _y, TAILLE, 2*TAILLE, -1, 0);
                }
                break;
            default :
                _conteneur[i] = nullptr;
                std::cout << "Pas d'obstacle à (" << _x+TAILLE*i << ", " << _y << ")" << std::endl;
                break;
            }
        }
        } break;

    default : {

        } break;
    }
    std::cout << std::endl;
}

void Chunk::move() {
    _x += _dx;
    int max = _conteneur.size();
    for(int i=0 ; i < max ; i++)
        _conteneur[i]->move();
}

// Détecte s'il y a collision entre la balle et un des éléments du chunk
bool Chunk::collision(Balle *_balle) const {
    bool collision_detectee = false;
    for(auto e : _conteneur) {
        if((_balle->getX()+_balle->getW() > e->getX() && _balle->getX()+_balle->getW() < e->getX()+e->getW())
                || (_balle->getX() > e->getX() && _balle->getX() < e->getX()+e->getW()))
        {
            collision_detectee = true;
        }
    }
    return collision_detectee;
}

std::string Chunk::objetTouche() const {
    return _conteneur[0]->getType();
}

int Chunk::taille() const
{
    return _conteneur.size();
}

std::string Chunk::getType(int index) const
{
    return _conteneur[index]->getType();
}
