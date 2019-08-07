#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

class Player {
    public:
    int x;
    int y;
    int saved_x;
    int saved_y;
    
    Player();
    Player(int x, int y);
    bool move(Grid *grid);
    
    private:
    bool check_step(Grid *grid, Direction direction);  // true if step is right false if not
    void save_coord();
    void restore_coord();
};

#endif
