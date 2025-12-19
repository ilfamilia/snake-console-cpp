#include "Board.h"

// Initializes the board with the given width and height.
// The initializer list is used for efficiency and clarity.
Board::Board(int width, int height)
    : width_(width), height_(height) {}

// Returns the total number of columns of the board.
int Board::getWidth() const {
    return width_;
}

// Returns the total number of rows of the board.
int Board::getHeight() const {
    return height_;
}

// Determines whether a given position corresponds to a wall.
// A wall is any cell located on the outer border of the board.
bool Board::isWall(int x, int y) const {
    return (x == 0 || x == width_ - 1 ||
            y == 0 || y == height_ - 1);
}

// Determines whether a position is inside the playable area.
// The playable area excludes the border walls and only includes
// the inner cells of the board.
bool Board::isInsidePlayable(int x, int y) const {
    return (x >= 1 && x <= width_ - 2 &&
            y >= 1 && y <= height_ - 2);
}

// Returns the logical center of the board.
// Integer division is used, which is appropriate for grid-based games
// (e.g., a 30x15 board will return {15, 7}).
Board::Point Board::center() const {
    return Point{ width_ / 2, height_ / 2 };
}
