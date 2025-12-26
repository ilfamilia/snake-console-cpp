#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "Renderer.h"
#include "Config.h"
#include "Direction.h"
#include "Point.h"

#include <conio.h>
#include <cctype>
#include <random>
#include <chrono>
#include <thread>

using namespace Config;

int main()
{
    // Random tools
    std::random_device rd;
    std::mt19937 engine(rd());

    std::uniform_int_distribution<> distX(1, BOARD_WIDTH - 2);
    std::uniform_int_distribution<> distY(1, BOARD_HEIGHT - 2);

    // Game tick timing (controls snake movement speed)
    using clock = std::chrono::steady_clock;
    auto lastTick = clock::now();
    const auto tick = std::chrono::milliseconds(120); 

    int score = 0;

    Board gameBoard(BOARD_WIDTH, BOARD_HEIGHT);
    Snake mySnake(gameBoard.center().x, gameBoard.center().y);

    // Generate food position ensuring it does not overlap the snake
    Point fPos;
    do {
        fPos.x = distX(engine);
        fPos.y = distY(engine);
    } while (fPos == mySnake.getPos());

    Food gameFood(fPos.x, fPos.y);

    Renderer gameDisplay;
    gameDisplay.hideCursor();
    gameDisplay.drawBoard(gameBoard);

    gameDisplay.drawScore(score);
    gameDisplay.drawChar(mySnake.getPos(), PLAYER_CHAR);
    gameDisplay.drawChar(gameFood.getPos(), FOOD_CHAR);

    while (true) {

        // Handle direction changes from keyboard input (WASD)
        if (_kbhit()) {
            const unsigned char raw = static_cast<unsigned char>(_getch());
            const char key = static_cast<char>(std::tolower(raw));

            if (key == 'w')      mySnake.setDirection(Direction::UP);
            else if (key == 's') mySnake.setDirection(Direction::DOWN);
            else if (key == 'a') mySnake.setDirection(Direction::LEFT);
            else if (key == 'd') mySnake.setDirection(Direction::RIGHT);
        }

        const auto now = clock::now();
        if ((now - lastTick) < tick) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            continue;
        }
        lastTick = now;

        const Point curPosBefore = mySnake.getPos();

        // Check next position before moving to detect wall collision
        const Point next = mySnake.peekNextPos();

        // Restart the game when the wall is hit by the snake
        if (gameBoard.isWall(next.x, next.y)) {
            gameDisplay.clearCell(curPosBefore);

            mySnake.resetPos(gameBoard.center().x, gameBoard.center().y);
            const Point centerPos = mySnake.getPos();
            gameDisplay.drawChar(centerPos, PLAYER_CHAR);

            if (gameFood.getPos() == centerPos) {
                Point newFood;
                do {
                    newFood.x = distX(engine);
                    newFood.y = distY(engine);
                } while (newFood == centerPos);

                gameFood.resetPos(newFood.x, newFood.y);
                gameDisplay.drawChar(gameFood.getPos(), FOOD_CHAR);
            }

            continue;
        }

        mySnake.move();

        const Point oldPos = mySnake.getOldPos();
        const Point curPos = mySnake.getPos();

        if (oldPos != curPos) {
            gameDisplay.clearCell(oldPos);
            gameDisplay.drawChar(curPos, PLAYER_CHAR);
        }

        if (gameFood.isEaten(curPos)) {
            Point newFood;
            do {
                newFood.x = distX(engine);
                newFood.y = distY(engine);
            } while (newFood == curPos);

            gameFood.resetPos(newFood.x, newFood.y);
            gameDisplay.drawChar(gameFood.getPos(), FOOD_CHAR);

            score++;
            gameDisplay.drawScore(score);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    gameDisplay.showCursor();
    gameDisplay.setCursorBelowBoard(gameBoard);
    return 0;
}