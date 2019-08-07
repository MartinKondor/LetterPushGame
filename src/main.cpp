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
    
    // Ask for input word
    cout << "Please give me a word: ";
    cin >> input_word;
    cout << endl;
    system("@cls");
    
    Grid grid = Grid(input_word);
    Player player = Player(1, 1);
    int word_row_number = -1;
    int word_col_number = 0;
    int i = 0;
    
    // Start the game loop
    while (true) {
        grid.grid[player.y][player.x] = PLAYER_CHAR;
        grid.show();
        
        cout << "Player: (" << player.y << ", " << player.x << ")" << endl;
        cout << "Word: ";
        for (i = 0; i < input_word.length(); i++) {
            cout << input_word[i];
        }
        cout << endl;
        
        while (!player.step(&grid)) {}
        grid.grid[player.y][player.x] = PLAYER_CHAR;
        
        grid.clear();
        
        // Checking winning conditions
        word_row_number = grid.letters[0].y;
        
        for (i = 0; i < sizeof(grid.letters) / sizeof(*grid.letters); i++) {
            if (grid.letters[i].y != word_row_number) {
                word_row_number = -1;
                break;
            }
        }
        
        if (false && word_row_number != -1) {
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
    
    delete grid;
    return 0;
}
