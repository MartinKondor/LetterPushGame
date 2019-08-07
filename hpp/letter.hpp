#ifndef _LETTER_HPP_
#define _LETTER_HPP_

class Letter {
  public:
  char letter;
  int x;
  int y;
  
  Letter();
  Letter(int y, int x, char letter);
  bool is_moveable(char grid[GRID_HEIGHT][GRID_WIDTH], Direction direction);
};

#endif
