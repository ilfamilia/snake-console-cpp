#ifndef FOOD_H
#define FOOD_H

#include "Point.h"

// Represents the food entity placed on the game board
class Food {
public:   
    Food(int posX, int posY);

    void resetPos(int posX, int posY);

    Point getPos() const;

    // Returns true if the snake occupies the food position
    bool isEaten(Point pos) const;

private:
    Point pos_;
};

#endif