#include "grid.hpp"


Grid::Grid() {
    this->init();
}

Grid::Grid(string input_word) {
    this->init();
    this->letters = new Letter[input_word.length()];
    
    // Place the characters of the word to the board
    for (int i = 0; i < input_word.length(); i++) {
        int* random_coords = this->get_random_free_coordinates();
        this->letters[i] = Letter(random_coords[0], random_coords[1], input_word[i]);
        this->grid[random_coords[0]][random_coords[1]] = input_word[i];
    }
}

void Grid::init() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            this->grid[i][j] = EMPTY_CHAR;
        }
    }
    
    // Randomly place N obstacles on the grid
    for (int i = 0; i < N_OBSTACLE; i++) {
        int* random_coords = this->get_random_free_coordinates();
        this->grid[random_coords[0]][random_coords[1]] = OBSTACLE_CHAR;
    }
}

int* Grid::get_random_free_coordinates() {
    int random_x = rand() % GRID_WIDTH;
    int random_y = rand() % GRID_HEIGHT;
    
    // Do it until it finds an empty place
    while (this->grid[random_y][random_x] != EMPTY_CHAR && random_y != 1 && random_x != 1) {
        random_x = rand() % GRID_WIDTH;
        random_y = rand() % GRID_HEIGHT;
    }
    
    return (int[]){random_y, random_x};
}

void Grid::show() {
    rlutil::saveDefaultColor();
    
    // Print upper walls
    for (int j = 0; j < GRID_WIDTH; j++) {
        cout << '-';
    }
    cout << endl;
    
    // Show letters
    for (int i = 0; i < sizeof(this->letters) / sizeof(*this->letters); i++) {
        this->grid[this->letters[i].y][this->letters[i].x] = this->letters[i].letter;
    }
    
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            rlutil::setBackgroundColor(rlutil::GREY);
            
            if (this->grid[i][j] == PLAYER_CHAR) {
                rlutil::setColor(rlutil::DARKGREY);
                cout << this->grid[i][j];
                rlutil::resetColor();
            }
            else if (this->grid[i][j] == OBSTACLE_CHAR) {
                rlutil::setColor(rlutil::GREEN);
                cout << this->grid[i][j];
                rlutil::resetColor();
            }
            else if (this->grid[i][j] != EMPTY_CHAR) {
                rlutil::setColor(rlutil::RED);
                cout << this->grid[i][j];
                rlutil::resetColor();
            }
            else {
                cout << this->grid[i][j];
            }
            
            rlutil::resetColor();
        }
        cout << '|' << endl;
    }
    
    for (int j = 0; j < GRID_WIDTH; j++) {
        cout << '-';
    }
    cout << endl;
    rlutil::resetColor();
}

void Grid::clear() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (this->grid[i][j] == PLAYER_CHAR) {
                this->grid[i][j] = EMPTY_CHAR;
            }
        }
    }
    
    // Clear screen
    COORD Position;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

Grid::~Grid() {
    
}
