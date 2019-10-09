#include "../hpp/base.hpp"


const void show_help() {
    rlutil::saveDefaultColor();
    rlutil::setColor(rlutil::YELLOW);
    cout << "Letter Push Game";
    rlutil::resetColor();

    rlutil::saveDefaultColor();
    rlutil::setColor(rlutil::WHITE);
    cout << " (v1.2)" << endl;
    cout << "Made by: ";
    cout << "Martin Kondor";
    cout << " (";
    rlutil::resetColor();

    rlutil::saveDefaultColor();
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "https://martinkondor.github.io/";
    rlutil::resetColor();

    rlutil::saveDefaultColor();
    rlutil::setColor(rlutil::WHITE);
    cout << ")" << endl;
    rlutil::resetColor();
    cout << endl;

    cout << "Controls" << endl;
    cout << "Arrows - Arrows are moving the player (" << PLAYER_CHAR << ")" << endl;
    cout << "ESC - Quit" << endl;
    cout << endl;
}

const void clear_screen() {
    COORD Position;
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}

const void show_grid(const char grid[GRID_HEIGHT][GRID_WIDTH]) {
    rlutil::saveDefaultColor();
    for (int j = 0; j < GRID_WIDTH + 2; j++) {  // Print upper walls
        cout << '-';
    }
    cout << endl;

    for (int i = 0; i < GRID_HEIGHT; i++) {
        cout << '|';  // Print side walls

        for (int j = 0; j < GRID_WIDTH; j++) {
            rlutil::setBackgroundColor(rlutil::GREY);
            if (grid[i][j] == PLAYER_CHAR) {
                rlutil::setColor(rlutil::LIGHTBLUE);
            }
            else if (grid[i][j] == OBSTACLE_CHAR) {
                rlutil::setColor(rlutil::RED);
            }
            else if (grid[i][j] != EMPTY_CHAR) {
                rlutil::setColor(rlutil::GREEN);
            }

            cout << grid[i][j];
        }

        rlutil::resetColor();
        cout << '|' << endl;  // Print side walls
    }

    for (int j = 0; j < GRID_WIDTH + 2; j++) {  // Print bottom walls
        cout << '-';
    }
    cout << endl;
    rlutil::resetColor();
}

std::vector<int> get_free_coords(const char grid[GRID_HEIGHT][GRID_WIDTH]) {
    int rand_y = 1;
    int rand_x = 1;

    do {
        rand_y = rand() % GRID_HEIGHT;
        rand_x = rand() % GRID_WIDTH;
    } while (rand_x >= GRID_WIDTH || rand_y >= GRID_HEIGHT || grid[rand_y][rand_x] != EMPTY_CHAR);

    return (std::vector<int>){rand_y, rand_x};
}

const void clear_grid(char grid[GRID_HEIGHT][GRID_WIDTH]) {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (grid[i][j] == PLAYER_CHAR) {
                grid[i][j] = EMPTY_CHAR;
            }
        }
    }
}

const bool check_letter_step(char grid[GRID_HEIGHT][GRID_WIDTH], const int &from_x, const int &from_y, const std::string &direction) {
    char ch = grid[from_y][from_x];

    if (direction == "up") {
        if (from_y - 1 < 0) {
            return false;
        }
        else if (grid[from_y - 1][from_x] != EMPTY_CHAR) {
            return false;
        }
        grid[from_y - 1][from_x] = ch;
    }
    else if (direction == "down") {
        if (from_y + 1 >= GRID_HEIGHT) {
            return false;
        }
        else if (grid[from_y + 1][from_x] != EMPTY_CHAR) {
            return false;
        }
        grid[from_y + 1][from_x] = ch;
    }
    else if (direction == "right") {
        if (from_x + 1 >= GRID_WIDTH) {
            return false;
        }
        else if (grid[from_y][from_x + 1] != EMPTY_CHAR) {
            return false;
        }
        grid[from_y][from_x + 1] = ch;
    }
    else if (direction == "left") {
        if (from_x - 1 < 0) {
            return false;
        }
        else if (grid[from_y][from_x - 1] != EMPTY_CHAR) {
            return false;
        }
        grid[from_y][from_x - 1] = ch;
    }

    return true;
}

const bool is_win(const char grid[GRID_HEIGHT][GRID_WIDTH]) {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (grid[i][j] == EMPTY_CHAR || grid[i][j] == PLAYER_CHAR || grid[i][j] == OBSTACLE_CHAR) {
                continue;
            }

            std::string found_word;

            for (int k = 0; k < GOAL_WORD.length(); k++) {
                found_word += grid[i][j + k];
            }

            if (found_word == GOAL_WORD) {
                return true;
            }
        }
    }
    return false;
}
