#ifndef SNAKE_H
#define SNAKE_H

// Represents the snake entity in the game.
// At this stage, the snake is modeled as a single segment with
// its current position and previous position.
class Snake {
public:
    // Simple 2D coordinate structure used to track the snake position.
    struct Point {
        int x;
        int y;
    };

    // Creates a snake at the given initial position.
    Snake(int posX, int posY);

    // Resets the snake position to the given coordinates.
    // Also updates the previous position accordingly.
    void resetPos(int posX, int posY);

    // Returns the current position of the snake.
    Point getPos() const;

    // Returns the previous position of the snake.
    // Useful for clearing the old character from the screen.
    Point getOldPos() const;

    // Moves the snake one cell upward.
    void moveUp();

    // Moves the snake one cell downward.
    void moveDown();

    // Moves the snake one cell to the left.
    void moveLeft();

    // Moves the snake one cell to the right.
    void moveRight();

private:
    // Current position of the snake.
    Point pos_;

    // Previous position of the snake (before the last move).
    Point oldPos_;
};

#endif // SNAKE_H
