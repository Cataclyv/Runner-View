#ifndef MOVABLEELEMENT_H
#define MOVABLEELEMENT_H

#include <string>
#include <iostream>

class MovableElement
{
protected :
    int _x, _y;
    int _w, _h;
    int _dx, _dy;

public:
    MovableElement(int x, int y, int w, int h, int dx, int dy);

    virtual ~MovableElement();
    void move();

    int getX() const;
    int getY() const;
    int getDx() const;
    int getDy() const;
    int getH() const;
    int getW() const;

    void setX(int x);
    void setY(int y);
    void setDx(int dx);
    void setDy(int dy);

    bool enJeu();

    virtual std::string getType() const;
};

#endif // MOVABLEELEMENT_H
