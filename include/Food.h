#ifndef FOOD_H
#define FOOD_H

#include "Point.h"

class Food {
public:   
    Food(int posX, int posY);

    void resetPos(int posX, int posY);

    Point getPos() const;

    bool isEaten(Point pos) const;

private:
    Point pos_;
};

#endif