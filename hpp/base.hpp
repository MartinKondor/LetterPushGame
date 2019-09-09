#ifndef _BASE_HPP_
#define _BASE_HPP_

const void show_help();
const void clear_screen();
const void show_grid(const char grid[GRID_HEIGHT][GRID_WIDTH]);
std::vector<int> get_free_coords(const char grid[GRID_HEIGHT][GRID_WIDTH]);
const void clear_grid(char grid[GRID_HEIGHT][GRID_WIDTH]);
const bool check_letter_step(char grid[GRID_HEIGHT][GRID_WIDTH], const int &new_x, const int &new_y, const std::string &direction);
const bool is_win(const char grid[GRID_HEIGHT][GRID_WIDTH]);

#endif // _BASE_HPP_
