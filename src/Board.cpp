#include "Board.h"

Board::Board(int width, int height)
    : width_(width), height_(height) {}

int Board::getWidth() const {
    return width_;
}

int Board::getHeight() const {
    return height_;
}

bool Board::isWall(int x, int y) const {
    return (x == 0 || x == width_ - 1 ||
            y == 0 || y == height_ - 1);
}

bool Board::isInsidePlayable(int x, int y) const {
    return (x >= 1 && x <= width_ - 2 &&
            y >= 1 && y <= height_ - 2);
}

Point Board::center() const {
    return Point{ width_ / 2, height_ / 2 };
}
