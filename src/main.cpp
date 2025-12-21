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

    // Draw the initial snake position
    gameDisplay.drawChar(
        mySnake.getPos().x,
        mySnake.getPos().y,
        PLAYER_CHAR
    );

    gameDisplay.drawChar(
        gameFood.getPos().x,
        gameFood.getPos().y,
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

        // Get the current snake position
        const Point pos = mySnake.getPos();

        // Predict the next position based on input
        int newX = pos.x;
        int newY = pos.y;

        if (key == 'w')      newY--;
        else if (key == 's') newY++;
        else if (key == 'a') newX--;
        else                 newX++;

        // Check for collision with the board walls
        if (gameBoard.isWall(newX, newY)) {

            // Clear the snake from its current position
            gameDisplay.clearCell(pos.x, pos.y);

            // Reset the snake to the center of the board
            mySnake.resetPos(
                gameBoard.center().x,
                gameBoard.center().y
            );

            // Draw the snake at the reset position
            const Point centerPos = mySnake.getPos();
            gameDisplay.drawChar(
                centerPos.x,
                centerPos.y,
                PLAYER_CHAR
            );

            // Skip movement and wait for the next input
            continue;
        }

        // Apply the movement based on the valid input
        if (key == 'w')      mySnake.moveUp();
        else if (key == 's') mySnake.moveDown();
        else if (key == 'a') mySnake.moveLeft();
        else                 mySnake.moveRight();

        // Retrieve old and current positions for rendering
        const Point oldPos = mySnake.getOldPos();
        const Point curPos = mySnake.getPos();

        // Clear the previous snake position
        gameDisplay.clearCell(oldPos.x, oldPos.y);

        // Draw the snake at its new position
        gameDisplay.drawChar(
            curPos.x,
            curPos.y,
            PLAYER_CHAR
        );

        if(gameFood.isEaten(mySnake.getPos())){
            fPosX = distX(engine);
            fPosY = distY(engine);
            
            gameFood.resetPos(fPosX, fPosY);
            
            gameDisplay.drawChar(
                gameFood.getPos().x,
                gameFood.getPos().y,
                FOOD_CHAR
            );
        }
    }

    // Restore console state (unreachable in current design)
    gameDisplay.showCursor();
    gameDisplay.setCursorBelowBoard(gameBoard);

    return 0;
}
