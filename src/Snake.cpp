#include "Snake.h"

// Initializes the snake at the given starting position.
// The previous position is set to the same value to avoid
// invalid data on the first frame.
Snake::Snake(int posX, int posY) {
    pos_.x = posX;
    pos_.y = posY;
    oldPos_ = pos_;
    currentDir_ = Direction::NONE;
}

// Resets the snake position to the given coordinates.
// This is typically used when restarting the game.
void Snake::resetPos(int posX, int posY) {
    pos_.x = posX;
    pos_.y = posY;
    oldPos_ = pos_;
    currentDir_ = Direction::NONE;
}

// Returns the current position of the snake.
Point Snake::getPos() const {
    return pos_;
}

// Returns the previous position of the snake.
// Useful for erasing the snake's last position from the screen.
Point Snake::getOldPos() const {
    return oldPos_;
}

Point Snake::peekNextPos() const {
    return pos_ + delta();
}

void Snake::setDirection(Direction dir){
    if (dir == opposite(currentDir_))
        return;

    currentDir_ = dir;
}

// Moves the snake one unit.
// The previous position is stored before updating the current one.
void Snake::move() {
    if (currentDir_ == Direction::NONE)
        return;

    oldPos_ = pos_;
    
    pos_ += delta();
}

Point Snake::delta() const {
    Point dPos = {0, 0};

    if (currentDir_ == Direction::NONE)
        return dPos;

    if (currentDir_ == Direction::UP) 
        dPos = {0, -1};
    else if (currentDir_ == Direction::DOWN)
        dPos = {0, 1};
    else if (currentDir_ == Direction::LEFT)
        dPos = {-1, 0};
    else if (currentDir_ == Direction::RIGHT) 
        dPos = {1, 0};
    
    return dPos;
}