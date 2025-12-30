#include "Renderer.h"
#include "Board.h"
#include "Config.h"
#include <iostream>
#include <windows.h>

void Renderer::drawBoard(const Board& board) const {

    // Clear the console before redrawing the board
    system("cls");

    const int w = board.getWidth();
    const int h = board.getHeight();

    Point pos;
    pos.x = 0;
    pos.y = 0;

    for (int y = 0; y < h; ++y) {
        pos.y = y;
        for (int x = 0; x < w; ++x) {
            pos.x = x;
            if (!board.isWall(pos)) {
                continue;
            }

            const bool left   = (pos.x == 0);
            const bool right  = (pos.x == w - 1);
            const bool top    = (pos.y == 0);
            const bool bottom = (pos.y == h - 1);

            const bool isCorner = (left || right) && (top || bottom);

            // Draw board boundaries (corners, horizontal and vertical edges)
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

void Renderer::drawScore(int score) const {
    Point lPos;
    Point sPos;
    
    // UI is drawn to the right of the board
    lPos.x = Config::BOARD_WIDTH + Config::UI_MARGIN;
    lPos.y = 1;

    sPos.x = Config::BOARD_WIDTH + Config::UI_MARGIN;
    sPos.y = 2;

    drawText(lPos, "SCORE:");
    drawText(sPos, std::to_string(score));
}

void Renderer::clearScore(int score) const {
    Point pos;
    std::string spaces;

    pos.x = Config::BOARD_WIDTH + Config::UI_MARGIN;
    pos.y = 2;

    spaces = "";

    while(score > 0) {
        spaces += " ";
        score = score / 10;
    }

    drawText(pos, spaces);
}

void Renderer::drawGameOver(int score) const {
    std::string gOverMessage = "GAME OVER";
    std::string scoreMessage = "SCORE: " + std::to_string(score);

    int gOverHalf = gOverMessage.length() / 2;
    int scHalf = scoreMessage.length() / 2;

    Point centerPos {Config::BOARD_WIDTH / 2, Config::BOARD_HEIGHT / 2};
    Point gOverPos {(centerPos.x - gOverHalf), centerPos.y};
    Point scPos {(centerPos.x - scHalf), (centerPos.y + 1)};

    drawText(gOverPos, gOverMessage);
    drawText(scPos, scoreMessage);
}

void Renderer::drawChar(Point chPos, char ch) const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = chPos.x;
    pos.Y = chPos.y;

    SetConsoleCursorPosition(hCon, pos);
    std::cout << ch;
}

void Renderer::drawText(Point tPos, std::string s) const {
    Point pos = tPos;
    
    // Draw text horizontally starting at tPos
    for(int i = 0; i < s.length(); i++){
        drawChar(pos, s[i]);
        pos.x += 1;
    }
}

void Renderer::clearCell(Point cPos) const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = cPos.x;
    pos.Y = cPos.y;

    SetConsoleCursorPosition(hCon, pos);
    std::cout << Config::EMPTY_CHAR;
}

void Renderer::hideCursor() const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hCon, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cursorInfo);
}

void Renderer::showCursor() const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hCon, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hCon, &cursorInfo);
}

void Renderer::setCursorBelowBoard(const Board& board) const {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = 0;
    pos.Y = board.getHeight() + 1;

    SetConsoleCursorPosition(hCon, pos);
}