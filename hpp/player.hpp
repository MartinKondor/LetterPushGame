#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

class Player {
public:
    int x;
    int y;
    int prev_x;
    int prev_y;

    Player(const int &x, const int &y);

    /**
    * @returns true if the update happened
    */
    const bool update(char grid[GRID_HEIGHT][GRID_WIDTH]);

    /**
    * @returns false if the position of the player is invalid
    */
    const bool check_step(char grid[GRID_HEIGHT][GRID_WIDTH], const std::string &direction);
};

#endif // _PLAYER_HPP_
