#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

#define GRID_HEIGHT 25
#define GRID_WIDTH 50
#define OBSTACLE_CHAR '#'
#define PLAYER_CHAR '@'
#define EMPTY_CHAR ' '
#define N_OBSTACLE 150
std::string GOAL_WORD = "";

#include "../hpp/rlutil.h"
#include "base.cpp"
#include "player.cpp"


int main(const int argc, const char** args) {
    srand(time(NULL));
    char grid[GRID_HEIGHT][GRID_WIDTH];
    Player player;
    int i = 0;


    // Ask for input word
    show_help();
    cout << "Write a word here: ";
    rlutil::saveDefaultColor();
    rlutil::setColor(rlutil::WHITE);
    cin >> GOAL_WORD;
    rlutil::resetColor();
    cout << endl;
    system("@cls");


    // Creating the grid
    for (i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = EMPTY_CHAR;
        }
    }


    // Save letters
    for (i = 0; i < GOAL_WORD.length(); i++) {
        std::vector<int> rand_coords = get_free_coords(grid);
        grid[rand_coords[0]][rand_coords[1]] = GOAL_WORD[i];
    }


    // Place obstacles to random coordinates
    for (i = 0; i < N_OBSTACLE; i++) {
        std::vector<int> rand_coords = get_free_coords(grid);
        grid[rand_coords[0]][rand_coords[1]] = OBSTACLE_CHAR;
    }


    // Main loop
    while (!is_win(grid)) {
        show_grid(grid);
        clear_grid(grid);
        clear_screen();

        // Update player's position
        while (!player.update(grid)) {
            if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {  // Escape is pressed down
                return EXIT_SUCCESS;
            }
        }
        grid[player.y][player.x] = PLAYER_CHAR;
    }


    system("@cls");

    if (GOAL_WORD.length() == 1) {
        cout << endl;
        cout << "-------------------------" << endl;
        cout << "|                       |" << endl;
        cout << "|       ";
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "CHEATER";
        rlutil::resetColor();
        cout << "         |" << endl;
        cout << "|                       |" << endl;
        cout << "-------------------------" << endl;
        cout << endl;
    }
    else {
        cout << endl;
        cout << "-------------------------" << endl;
        cout << "|                       |" << endl;
        cout << "|    ";
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "CONGRATULATIONS";
        rlutil::resetColor();
        cout << "    |" << endl;
        cout << "|                       |" << endl;
        cout << "-------------------------" << endl;
        cout << endl;
    }

    system("@pause");
    return EXIT_SUCCESS;
}
