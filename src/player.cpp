#include "player.hpp"


Player::Player() {
    this->x = 0;
    this->y = 0;
}

Player::Player(int x, int y) {
    this->x = x;
    this->y = y;
    this->saved_x = 0;
    this->saved_y = 0;
}

void Player::save_coord() {
    this->saved_x = this->x;
    this->saved_y = this->y;
}

void Player::restore_coord() {
    this->x = this->saved_x;
    this->y = this->saved_y;
}

bool Player::check_step(Grid *grid, Direction direction) {
    if (grid->grid[this->y][this->x] == OBSTACLE_CHAR) {
        this->restore_coord();
        return false;
    }
    
    // Checking letter collusion
    for (int i = 0; i < sizeof(grid->letters) / sizeof(*grid->letters); i++) {
        if (grid->letters[i].y == this->y && grid->letters[i].x == this->x) {
            
            if (direction == Direction::UP && grid->letters[i].y != 0 &&
                grid->letters[i].is_moveable(grid->grid, Direction::UP)) {
                grid->letters[i].y--;
                return true;
            }
            else if (direction == Direction::DOWN && grid->letters[i].y != GRID_HEIGHT - 1 && 
                grid->letters[i].is_moveable(grid->grid, Direction::DOWN)) {
                grid->letters[i].y++;
                return true;
            }
            else if (direction == Direction::LEFT && grid->letters[i].x != 0 &&
                grid->letters[i].is_moveable(grid->grid, Direction::LEFT)) {
                grid->letters[i].x--;
                return true;
            }
            else if (direction == Direction::RIGHT && grid->letters[i].x != GRID_WIDTH - 1 &&
                grid->letters[i].is_moveable(grid->grid, Direction::RIGHT)) {
                grid->letters[i].x++;
                return true;
            }
            
            return false;
        }
    }
    
    return true;
}

bool Player::step(Grid *grid) {
    this->save_coord();
    
    if ((GetAsyncKeyState(VK_UP) & 0x8000) && this->y != 0) {
        this->y--;
        return this->check_step(grid, Direction::UP);
    }
    if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && this->y != GRID_HEIGHT - 1) {
        this->y++;
        return this->check_step(grid, Direction::DOWN);
    }
    if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && this->x != GRID_WIDTH - 1) {
        this->x++;
        return this->check_step(grid, Direction::RIGHT);
    }
    if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && this->x != 0) {
        this->x--;
        return this->check_step(grid, Direction::LEFT);
    }
    
    return false;
}
