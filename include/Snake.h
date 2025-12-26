#ifndef SNAKE_H
#define SNAKE_H

#include "Point.h"
#include "Direction.h"

// Represents the snake entity and its movement logic
class Snake {
public:
    Snake(int posX, int posY);

    // Resets the snake position and clears movement state
    void resetPos(int posX, int posY);

    Point getPos() const;

    // Returns the previous position before the last move
    Point getOldPos() const;

    // Computes the next position based on current direction without moving
    Point peekNextPos() const;

    // Updates the current movement direction
    void setDirection(Direction dir);

    // Moves the snake one step in the current direction (ignored if NONE)
    void move();

private:
    Point pos_;
    Point oldPos_;
    Direction currentDir_;

    // Converts the current direction into a movement delta
    Point delta() const;
};

#endif
