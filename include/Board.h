#ifndef BOARD_H
#define BOARD_H

#include "Point.h"

// Represents the game board dimensions and helper utilities
// to validate positions (walls vs playable area) and find key points.
class Board {
public:
    // Constructs a board with the given dimensions.
    // width  = number of columns
    // height = number of rows
    Board(int width, int height);

    // Returns the total number of columns of the board.
    int getWidth() const;

    // Returns the total number of rows of the board.
    int getHeight() const;

    // Returns true if the position (x, y) is a wall/border cell.
    // Typically used to prevent the snake from moving through boundaries.
    bool isWall(int x, int y) const;

    // Returns true if the position (x, y) is inside the playable area,
    // meaning it is within the board but not on the border walls.
    bool isInsidePlayable(int x, int y) const;

    // Returns the logical center of the board.
    // Useful for spawning the snake or placing initial elements.
    Point center() const;

private:
    // Board dimensions stored internally.
    int width_;
    int height_;
};

#endif // BOARD_H
