#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "Renderer.h"
#include "Config.h"

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

    // Generate food position ensuring it does not overlap the snake head
    Point fPos;
    do {
        fPos.x = distX(engine);
        fPos.y = distY(engine);
    } while (fPos == mySnake.getHeadPos());

    Food gameFood(fPos.x, fPos.y);

    Renderer gameDisplay;
    gameDisplay.hideCursor();
    gameDisplay.drawBoard(gameBoard);

    gameDisplay.drawScore(score);
    gameDisplay.drawChar(mySnake.getHeadPos(), PLAYER_CHAR);
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

        // Predict next position before moving (collision check)
        const Point next = mySnake.peekNextPos();

        // Wall collision: clear the entire snake body from screen, reset snake
        if (gameBoard.isWall(next.x, next.y)) {

            // Clear all snake segments currently on screen
            for (const Point& p : mySnake.getBody()) {
                gameDisplay.clearCell(p);
            }

            mySnake.resetPos(gameBoard.center().x, gameBoard.center().y);

            const Point head = mySnake.getHeadPos();
            gameDisplay.drawChar(head, PLAYER_CHAR);

            // Ensure food isn't under the snake after reset
            if (gameFood.getPos() == head) {
                Point newFood;
                do {
                    newFood.x = distX(engine);
                    newFood.y = distY(engine);
                } while (newFood == head);

                gameFood.resetPos(newFood.x, newFood.y);
                gameDisplay.drawChar(gameFood.getPos(), FOOD_CHAR);
            }

            continue;
        }

        // Move snake
        const Point oldHead = mySnake.getHeadPos();
        mySnake.move();
        const Point newHead = mySnake.getHeadPos();

        if (newHead != oldHead) {
            gameDisplay.drawChar(newHead, PLAYER_CHAR);

            // Clear tail only if a tail segment was actually removed (not growing)
            if (mySnake.didRemoveTail()) {
                gameDisplay.clearCell(mySnake.getRemovedTailPos());
            }
        }

        // Food collision 
        if (gameFood.isEaten(newHead)) {

            mySnake.grow(1);

            Point newFood;
            do {
                newFood.x = distX(engine);
                newFood.y = distY(engine);
            } while (newFood == newHead);

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