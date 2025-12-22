#include "Renderer.h"
#include "Board.h"
#include "Config.h"
#include <iostream>
#include <windows.h>

// Draws the full game board to the console.
// This includes clearing the screen and rendering the borders
// based on the board dimensions.
void Renderer::drawBoard(const Board& board) const {
    // Clear the console before drawing the board
    system("cls");

    const int w = board.getWidth();
    const int h = board.getHeight();

    Point pos;
    pos.x = 0;
    pos.y = 0;

    // Iterate over every cell in the board grid
    for (int y = 0; y < h; ++y) {
        pos.y = y;
        for (int x = 0; x < w; ++x) {
            pos.x = x;
            // Skip non-wall cells to avoid unnecessary drawing
            if (!board.isWall(pos.x, pos.y)) {
                // drawChar(x, y, Config::EMPTY_CHAR);
                continue;
            }

            // Determine which side of the board the cell belongs to
            const bool left   = (pos.x == 0);
            const bool right  = (pos.x == w - 1);
            const bool top    = (pos.y == 0);
            const bool bottom = (pos.y == h - 1);

            // A corner is where a horizontal and vertical wall meet
            const bool isCorner = (left || right) && (top || bottom);

            // Select the appropriate character based on the wall type
            if (isCorner) {
                drawChar(pos, Config::CORNER_CHAR);
            } else if (top || bottom) {
                drawChar(pos, Config::HORIZONTAL_CHAR);
            } else {
                drawChar(pos, Config::VERTICAL_CHAR);
            }
        }
    }
}

// Draws a single character at the specified console coordinates.
void Renderer::drawChar(Point chPos, char ch) const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = chPos.x;
    pos.Y = chPos.y;

    // Move the cursor and print the character
    SetConsoleCursorPosition(hCon, pos);
    std::cout << ch;
}

void Renderer::drawText(Point tPos, std::string s) const {
    Point pos = tPos;
    
    for(int i = 0; i < s.length(); i++){
        drawChar(pos, s[i]);
        pos.x += 1;
    }
}

// Clears a single cell by overwriting it with the empty character.
void Renderer::clearCell(Point cPos) const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = cPos.x;
    pos.Y = cPos.y;

    // Move the cursor and print the empty space
    SetConsoleCursorPosition(hCon, pos);
    std::cout << Config::EMPTY_CHAR;
}

// Hides the console cursor to improve the visual experience during gameplay.
void Renderer::hideCursor() const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hCon, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cursorInfo);
}

// Shows the console cursor again (useful when the game ends).
void Renderer::showCursor() const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hCon, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hCon, &cursorInfo);
}

// Moves the console cursor to a position below the board.
// This allows text output (score, messages) without interfering
// with the game area.
void Renderer::setCursorBelowBoard(const Board& board) const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = 0;
    pos.Y = board.getHeight() + 1;

    SetConsoleCursorPosition(hCon, pos);
}
