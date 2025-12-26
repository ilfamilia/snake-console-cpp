#ifndef BOARD_H
#define BOARD_H

#include "Point.h"

// Represents the game board and its boundaries
class Board {
public:
    Board(int width, int height);

    int getWidth() const;

    int getHeight() const;

    // Returns true if the position corresponds to a board boundary
    bool isWall(int x, int y) const;

    // Checks whether a position is inside the playable area (excluding walls)
    bool isInsidePlayable(int x, int y) const;

    // Returns the center position of the board
    Point center() const;

private:
    int width_;
    int height_;
};

#endif 
