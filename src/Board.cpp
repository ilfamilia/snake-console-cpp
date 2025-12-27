#include "Board.h"

Board::Board(int width, int height)
    : width_(width), height_(height) {}

int Board::getWidth() const {
    return width_;
}

int Board::getHeight() const {
    return height_;
}

bool Board::isWall(Point pos) const {
    return (pos.x == 0 || pos.x == width_ - 1 ||
            pos.y == 0 || pos.y == height_ - 1);
}

bool Board::isInsidePlayable(Point pos) const {
    return (pos.x >= 1 && pos.x <= width_ - 2 &&
            pos.y >= 1 && pos.y <= height_ - 2);
}

Point Board::center() const {
    return Point{ width_ / 2, height_ / 2 };
}
