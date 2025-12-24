#ifndef DIRECTION_H
#define DIRECTION_H

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

inline Direction opposite(Direction dir){
    if (dir == Direction::UP)
        return Direction::DOWN;
    else if (dir == Direction::DOWN)
        return Direction::UP;
    else if (dir == Direction::LEFT)
        return Direction::RIGHT;
    else if (dir == Direction::RIGHT)
        return Direction::LEFT;
    return dir;
}

#endif