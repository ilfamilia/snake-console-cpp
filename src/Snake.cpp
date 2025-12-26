#include "Snake.h"

Snake::Snake(int posX, int posY) {
    pos_.x = posX;
    pos_.y = posY;
    oldPos_ = pos_;
    currentDir_ = Direction::NONE;
}

void Snake::resetPos(int posX, int posY) {
    pos_.x = posX;
    pos_.y = posY;
    oldPos_ = pos_;
    currentDir_ = Direction::NONE;
}

Point Snake::getPos() const {
    return pos_;
}

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