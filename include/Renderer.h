#ifndef RENDERER_H
#define RENDERER_H

// Forward declaration to avoid including Board.h in the header
// and reduce compilation dependencies.
class Board;

// Handles all console rendering responsibilities.
// This class is responsible only for drawing and cursor control,
// keeping rendering logic separated from game logic.
class Renderer {
public:
    // Draws the complete game board, including its borders.
    void drawBoard(const Board& board) const;

    // Draws a single character at the given board coordinates.
    // Used to render the snake, food, or any other game element.
    void drawChar(int x, int y, char ch) const;

    // Clears a single cell at the given coordinates.
    // Typically used to erase the snake's previous position.
    void clearCell(int x, int y) const;

    // Hides the console cursor to improve visual appearance during gameplay.
    void hideCursor() const;

    // Shows the console cursor again (useful when exiting the game).
    void showCursor() const;

    // Moves the console cursor to a position just below the board.
    // Useful for printing messages (score, instructions, etc.)
    // without interfering with the game area.
    void setCursorBelowBoard(const Board& board) const;
};

#endif // RENDERER_H
