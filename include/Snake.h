#ifndef SNAKE_H
#define SNAKE_H

#include "Point.h"
#include "Direction.h"
#include <deque>

// Represents the snake entity and its movement logic.
class Snake {
public:
    Snake(int posX, int posY);

    // Resets the snake position and clears movement/growth state.
    void resetPos(int posX, int posY);

    Point getHeadPos() const;

    Point getTailPos() const;

    // Access to the whole body (for collision checks, etc).
    const std::deque<Point>& getBody() const;

    // Growth request (consumed on future moves).
    void grow(int amount = 1);

    // Computes the next head position without moving.
    Point peekNextPos() const;

    // Updates the movement direction (blocks instant 180°).
    void setDirection(Direction dir);

    // Moves the snake one step in the current direction (ignored if NONE).
    void move();

    bool hasSelfCollision() const;

    bool didRemoveTail() const;

    Point getRemovedTailPos() const;

private:
    std::deque<Point> body_;

    // Tail removed on the last move (only when not growing).
    Point removedTail_{0, 0};
    bool removedTailValid_ = false;

    Direction currentDir_ = Direction::NONE;
    int growPending_ = 0;

    // Converts the current direction into a movement delta.
    Point delta() const;
};

#endif