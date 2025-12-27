#ifndef RENDERER_H
#define RENDERER_H

#include "Point.h"
#include <string>

class Board;

// Handles all console rendering for the game
class Renderer {
public:
    void drawBoard(const Board& board) const;

    void drawScore(int score) const;

    void clearScore(int score) const;

    void drawChar(Point chPos, char ch) const;

    // Draws a text string starting at the given position
    void drawText(Point tPos, std::string s) const;

    // Clears a single cell by restoring the empty character
    void clearCell(Point cPos) const;

    void hideCursor() const;

    void showCursor() const;

    // Moves the console cursor below the board to avoid overwriting game output
    void setCursorBelowBoard(const Board& board) const;
};

#endif