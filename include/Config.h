#ifndef CONFIG_H
#define CONFIG_H

// Centralized configuration values for the game.
// This namespace groups all constants related to board size,
// rendering characters, and player representation.
namespace Config {

    // Board dimensions (width = columns, height = rows)
    inline constexpr int BOARD_WIDTH  = 30;
    inline constexpr int BOARD_HEIGHT = 15;

    // Characters used to render the board borders
    inline constexpr char CORNER_CHAR     = '+';
    inline constexpr char HORIZONTAL_CHAR = '-';
    inline constexpr char VERTICAL_CHAR   = '|';

    // Character used to represent an empty cell
    inline constexpr char EMPTY_CHAR      = ' ';

    // Character used to represent the player (snake head)
    inline constexpr char PLAYER_CHAR = '@';

    // Character used to represent the food
    inline constexpr char FOOD_CHAR = 'f';
}

#endif // CONFIG_H
