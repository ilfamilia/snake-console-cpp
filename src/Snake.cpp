#include "Snake.h"

// Initializes the snake at the given starting position.
// The previous position is set to the same value to avoid
// invalid data on the first frame.
Snake::Snake(int posX, int posY) {
    pos_.x = posX;
    pos_.y = posY;
    oldPos_ = pos_;
}

// Resets the snake position to the given coordinates.
// This is typically used when restarting the game.
void Snake::resetPos(int posX, int posY) {
    pos_.x = posX;
    pos_.y = posY;
    oldPos_ = pos_;
}

// Returns the current position of the snake.
Snake::Point Snake::getPos() const {
    return pos_;
}

// Returns the previous position of the snake.
// Useful for erasing the snake's last position from the screen.
Snake::Point Snake::getOldPos() const {
    return oldPos_;
}

// Moves the snake one unit upward.
// The previous position is stored before updating the current one.
void Snake::moveUp() {
    oldPos_ = pos_;
    pos_.y--;
}

// Moves the snake one unit downward.
// The previous position is stored before updating the current one.
void Snake::moveDown() {
    oldPos_ = pos_;
    pos_.y++;
}

// Moves the snake one unit to the left.
// The previous position is stored before updating the current one.
void Snake::moveLeft() {
    oldPos_ = pos_;
    pos_.x--;
}

// Moves the snake one unit to the right.
// The previous position is stored before updating the current one.
void Snake::moveRight() {
    oldPos_ = pos_;
    pos_.x++;
}
