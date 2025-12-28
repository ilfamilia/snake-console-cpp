#include "Snake.h"

Snake::Snake(int posX, int posY) {
    resetPos(posX, posY);
}

void Snake::resetPos(int posX, int posY) {
    body_.clear();
    body_.push_back(Point{posX, posY});

    growPending_ = 0;
    currentDir_ = Direction::NONE;

    removedTailValid_ = false;
    removedTail_ = Point{0, 0};
}

Point Snake::getHeadPos() const {
    return body_.front();
}

Point Snake::getTailPos() const {
    return body_.back();
}

const std::deque<Point>& Snake::getBody() const {
    return body_;
}

void Snake::grow(int amount) {
    if (amount > 0) {
        growPending_ += amount;
    }
}

Point Snake::peekNextPos() const {
    return getHeadPos() + delta();
}

void Snake::setDirection(Direction dir) {
    if (dir == Direction::NONE) {
        return;
    }

    if (currentDir_ != Direction::NONE && dir == opposite(currentDir_)) {
        return;
    }

    currentDir_ = dir;
}

void Snake::move() {
    removedTailValid_ = false;

    if (currentDir_ == Direction::NONE) {
        return;
    }

    const Point nextHead = peekNextPos();
    body_.push_front(nextHead);

    if (growPending_ > 0) {
        --growPending_;
        return;
    }

    removedTail_ = body_.back();
    removedTailValid_ = true;
    body_.pop_back();
}

bool Snake::hasSelfCollision() const {
    
    const auto& body = getBody();
    const Point& head = body.front();
    
    for (std::size_t i = 1; i < body.size(); ++i){
        if (head == body.at(i)) {
            return true;
        }
    }
    return false;
}

bool Snake::didRemoveTail() const {
    return removedTailValid_;
}

Point Snake::getRemovedTailPos() const {
    return removedTail_;
}

Point Snake::delta() const {
    if (currentDir_ == Direction::UP) {
        return Point{0, -1};
    }
    if (currentDir_ == Direction::DOWN) {
        return Point{0, 1};
    }
    if (currentDir_ == Direction::LEFT) {
        return Point{-1, 0};
    }
    if (currentDir_ == Direction::RIGHT) {
        return Point{1, 0};
    }
    return Point{0, 0}; 
}