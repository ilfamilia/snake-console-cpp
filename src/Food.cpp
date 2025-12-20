#include "Food.h"

Food::Food(int posX, int posY){
    pos_.x = posX;
    pos_.y = posY;
}

void Food::resetPos(int posX, int posY){
    pos_.x = posX;
    pos_.y = posY;
}

Point Food::getPos() const {
    return pos_;
}

bool Food::isEaten(Point pos) const {
    return pos_ == pos;
}