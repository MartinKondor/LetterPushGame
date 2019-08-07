#ifndef _GRID_HPP_
#define _GRID_HPP_

class Grid {
    public:
    char grid[GRID_HEIGHT][GRID_WIDTH];
    Letter* letters;
    
    Grid();
    Grid(string input_word);
    ~Grid();
    void show();
    void clear();
    
    private:
    void init();
    int* get_random_free_coordinates(bool include_sides);
};

#endif
