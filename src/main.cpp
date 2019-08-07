#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "rlutil.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

#define GRID_HEIGHT 18
#define GRID_WIDTH 34

#define OBSTACLE_CHAR '#'
#define PLAYER_CHAR '@'
#define EMPTY_CHAR ' '
#define N_OBSTACLE (5 * GRID_HEIGHT * GRID_WIDTH) / 100

enum class Direction {
    UP, 
    DOWN,
    LEFT,
    RIGHT
};

#include "letter.cpp"
#include "grid.cpp"
#include "player.cpp"


int main(int argc, char ** args) {
    srand(time(NULL));
    string input_word;
    auto start_time = time(NULL);
    
    // Ask for input word
    cout << "Please give me a word: ";
    cin >> input_word;
    cout << endl;
    system("@cls");
    
    Grid grid = Grid(input_word);
    Player player = Player(1, 1);
    bool is_game_over = false;
    int i = 0;
    
    // Start the game loop
    while (true) {
        grid.grid[player.y][player.x] = PLAYER_CHAR;
        grid.show();
        
        // Print some information
        cout << "Player: (" << player.y << ", " << player.x << ")" << endl;
        cout << "Word: ";
        for (i = 0; i < input_word.length(); i++) {
            cout << input_word[i];
        }
        cout << "Playing since: " << time(NULL) - start_time << " seconds";
        cout << endl;
        
        // Wait for input
        while (!player.move(&grid)) {}
        grid.grid[player.y][player.x] = PLAYER_CHAR;
        grid.clear();
        
        // Checking winning conditions
        
        
        if (is_game_over) {
            cout << endl;
            cout << "------------------------" << endl;
            cout << "|                      |" << endl;
            cout << "|      ";
            
            rlutil::saveDefaultColor();
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "GAME OVER";
            rlutil::resetColor();
            
            cout << "       |" << endl;
            cout << "|                      |" << endl;
            cout << "------------------------" << endl;
            cout << endl;
            
            return 0;
        }
    }
    
    delete &grid;
    return 0;
}
