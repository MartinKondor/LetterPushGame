#include "letter.hpp"


Letter::Letter()  {
    this->y = 0;
    this->x = 0;
    this->letter = EMPTY_CHAR;
}

Letter::Letter(int y, int x, char letter) {
    this->y = y;
    this->x = x;
    this->letter = letter;
}

bool Letter::is_moveable(char grid[GRID_HEIGHT][GRID_WIDTH], Direction direction) {
    int newx = this->x;
    int newy = this->y;
      
    // Move the newy, newx according to the Direction
    if (direction == Direction::UP) {
        --newy;
    }
    else if (direction == Direction::DOWN) {
        ++newy;
    }
    else if (direction == Direction::LEFT) {
        --newx;
    }
    else if (direction == Direction::RIGHT) {
        ++newx;
    }
     
    if (grid[newy][newx] == OBSTACLE_CHAR || newx == -1 || newx == GRID_WIDTH - 2 || newy == -1 || newy == GRID_HEIGHT - 2) {
        return false;
    }
        
    return grid[newy][newx] == EMPTY_CHAR;
}
