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

    // Iterate over every cell in the board grid
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {

            // Skip non-wall cells to avoid unnecessary drawing
            if (!board.isWall(x, y)) {
                // drawChar(x, y, Config::EMPTY_CHAR);
                continue;
            }

            // Determine which side of the board the cell belongs to
            const bool left   = (x == 0);
            const bool right  = (x == w - 1);
            const bool top    = (y == 0);
            const bool bottom = (y == h - 1);

            // A corner is where a horizontal and vertical wall meet
            const bool isCorner = (left || right) && (top || bottom);

            // Select the appropriate character based on the wall type
            if (isCorner) {
                drawChar(x, y, Config::CORNER_CHAR);
            } else if (top || bottom) {
                drawChar(x, y, Config::HORIZONTAL_CHAR);
            } else {
                drawChar(x, y, Config::VERTICAL_CHAR);
            }
        }
    }
}

// Draws a single character at the specified console coordinates.
void Renderer::drawChar(int x, int y, char ch) const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = x;
    pos.Y = y;

    // Move the cursor and print the character
    SetConsoleCursorPosition(hCon, pos);
    std::cout << ch;
}

// Clears a single cell by overwriting it with the empty character.
void Renderer::clearCell(int x, int y) const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = x;
    pos.Y = y;

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
