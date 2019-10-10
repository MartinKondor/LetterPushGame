#include "../hpp/player.hpp"


Player::Player(const int &x=PLAYER_DEFAULT_X, const int &y=PLAYER_DEFAULT_Y) {
    this->x = x;
    this->y = y;
    this->prev_x = x;
    this->prev_y = y;
}

const bool Player::update(char grid[GRID_HEIGHT][GRID_WIDTH]) {
    this->prev_x = this->x;
    this->prev_y = this->y;

    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        if (this->y > 0) {
            this->y--;
        }
        return this->check_step(grid, "up");
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        if (this->y < GRID_HEIGHT - 1) {
            this->y++;
        }
        return this->check_step(grid, "down");
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        if (this->x < GRID_WIDTH - 1) {
            this->x++;
        }
        return this->check_step(grid, "right");
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        if (this->x > 0) {
            this->x--;
        }
        return this->check_step(grid, "left");
    }
    return false;
}

const bool Player::check_step(char grid[GRID_HEIGHT][GRID_WIDTH], const std::string &direction) {
    if (grid[this->y][this->x] == OBSTACLE_CHAR) {
        this->x = this->prev_x;
        this->y = this->prev_y;
        return false;
    }
    else if (grid[this->y][this->x] != EMPTY_CHAR) {  // A letter, probably
        if (!check_letter_step(grid, this->x, this->y, direction)) {
            this->x = this->prev_x;
            this->y = this->prev_y;
        }
        return true;
    }
    return true;
}
