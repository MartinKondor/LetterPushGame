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
#define N_OBSTACLE (4 * GRID_HEIGHT * GRID_WIDTH) / 100

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
    int i, first_y, prev_x;
    bool is_game_over;
    
    // Start the game loop
    while (true) {
        grid.grid[player.y][player.x] = PLAYER_CHAR;
        grid.show();
        Sleep(20);
        
        // Print some information
        cout << "Player: (" << player.y << ", " << player.x << ")" << endl;
        cout << "Word: ";
        for (i = 0; i < input_word.length(); i++) {
            cout << input_word[i];
        }
        cout << endl << "Playing since: " << time(NULL) - start_time << " seconds";
        cout << endl;
        
        // Wait for input
        while (!player.move(&grid)) {}
        grid.grid[player.y][player.x] = PLAYER_CHAR;
        grid.clear();
        
        // Checking winning conditions
        prev_x = grid.letters[0].x;
        first_y = grid.letters[0].y;
        
        if (prev_x + grid.n_letters < GRID_WIDTH) {
            is_game_over = true;
            
            for (i = 0; i < grid.n_letters; i++) {
                if (grid.letters[i].y != first_y) {  // If they are not in the same row
                    is_game_over = false;
                    break;
                }
                
                if (i != 0 && grid.letters[i].x != (prev_x + 1)) {  // If they are not in the same order
                    is_game_over = false;
                    break;
                }
                else if (i != 0) {
                    prev_x = grid.letters[i].x;
                }
            }
        }
        
        if (is_game_over) {
            Sleep(500);
            system("@cls");
            
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
