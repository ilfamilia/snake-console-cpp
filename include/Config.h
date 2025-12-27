#ifndef CONFIG_H
#define CONFIG_H

// Global configuration constants for game layout and rendering
namespace Config {

    inline constexpr int GAME_TICK_MS = 120;

    inline constexpr int BOARD_WIDTH  = 30;
    inline constexpr int BOARD_HEIGHT = 15;

    // Spacing between the game board and UI elements
    inline constexpr int UI_MARGIN = 3;

    inline constexpr char CORNER_CHAR     = '+';
    inline constexpr char HORIZONTAL_CHAR = '-';
    inline constexpr char VERTICAL_CHAR   = '|';

    inline constexpr char EMPTY_CHAR      = ' ';

    inline constexpr char PLAYER_CHAR = '@';

    inline constexpr char FOOD_CHAR = '*';
}

#endif
