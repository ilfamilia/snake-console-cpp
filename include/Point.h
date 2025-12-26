#ifndef POINT_H
#define POINT_H

// Simple 2D point used for board and entity positions
struct Point
{
    int x;
    int y;

    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    Point operator+(const Point& other) const {
        Point result = *this;
        return result += other;
    }

    Point& operator+=(const Point& other) {
        this->x += other.x;
        this->y += other.y;

        return *this;
    }
};

#endif