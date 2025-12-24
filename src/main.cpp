#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "Renderer.h"
#include "Config.h"
#include <conio.h>
#include <cctype>
#include <random>

using namespace Config;

int main()
{
    std::random_device rd;
    std::mt19937 engine(rd());

    std::uniform_int_distribution <> distX(1, BOARD_WIDTH - 2);
    std::uniform_int_distribution <> distY(1, BOARD_HEIGHT - 2);

    int fPosX = distX(engine);
    int fPosY = distY(engine);

    int score = 0;
    
    // Create the game board using predefined dimensions
    Board gameBoard(BOARD_WIDTH, BOARD_HEIGHT);

    // Initialize the snake at the logical center of the board
    Snake mySnake(gameBoard.center().x, gameBoard.center().y);

    Food gameFood(fPosX, fPosY);

    // Renderer responsible for all console drawing
    Renderer gameDisplay;

    // Prepare the console for gameplay
    gameDisplay.hideCursor();
    gameDisplay.drawBoard(gameBoard);

    gameDisplay.drawScore(score);

    // Draw the initial snake position
    gameDisplay.drawChar(
        mySnake.getPos(),
        PLAYER_CHAR
    );

    gameDisplay.drawChar(
        gameFood.getPos(),
        FOOD_CHAR
    );

    // Main game loop (runs indefinitely)
    while (true) {

        // Check if a key has been pressed
        if (!_kbhit()) {
            continue; // Non-blocking input
        }

        // Read and normalize the input character
        const char key = static_cast<char>(tolower(_getch()));

        // Ignore any input that is not a movement key
        if (key != 'w' && key != 'a' && key != 's' && key != 'd') {
            continue;
        }

        if (key == 'w')      mySnake.setDirection(Direction::UP);
        else if (key == 's') mySnake.setDirection(Direction::DOWN);
        else if (key == 'a') mySnake.setDirection(Direction::LEFT);
        else if (key == 'd') mySnake.setDirection(Direction::RIGHT);

        Point next = mySnake.peekNextPos();

        // Check for collision with the board walls
        if (gameBoard.isWall(next.x, next.y)) {

            // Clear the snake from its current position
            gameDisplay.clearCell(mySnake.getPos());

            // Reset the snake to the center of the board
            mySnake.resetPos(
                gameBoard.center().x,
                gameBoard.center().y
            );

            // Draw the snake at the reset position
            const Point centerPos = mySnake.getPos();
            gameDisplay.drawChar(centerPos, PLAYER_CHAR);

            // Skip movement and wait for the next input
            continue;
        }

        mySnake.move();

        // Retrieve old and current positions for rendering
        const Point oldPos = mySnake.getOldPos();
        const Point curPos = mySnake.getPos();

        // Clear the previous snake position
        gameDisplay.clearCell(oldPos);

        // Draw the snake at its new position
        gameDisplay.drawChar(curPos, PLAYER_CHAR);

        if(gameFood.isEaten(curPos)){
            Point fPos;
            do {
                fPos.x = distX(engine);
                fPos.y = distY(engine);
            } while (fPos == curPos);

            gameFood.resetPos(fPos.x, fPos.y);

            gameDisplay.drawChar(gameFood.getPos(), FOOD_CHAR);

            score++;
            gameDisplay.drawScore(score);
        }
    }

    // Restore console state (unreachable in current design)
    gameDisplay.showCursor();
    gameDisplay.setCursorBelowBoard(gameBoard);

    return 0;
}
