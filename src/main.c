#include <ncurses.h>
#include <unistd.h>
#include <math.h>
#include "gol.h"
#include "sprites.h"
#include "color-helpers.h"

int main() {
  initscr();
  keypad(stdscr, TRUE);
  cbreak();
  noecho();

  if (has_colors() == FALSE) {
    endwin();
    printf("Your terminal does not support color\n");
    return 1;
  }

  curs_set(0);

  start_color();
  init_colorpairs();

  char grid[LINES][COLS];

  init_grid(grid);
  sprite_projection(glider, grid, 45, 0);
  sprite_projection(pulsar, grid, floor(COLS / 2), floor(LINES / 2));

  int timer = 100000;
  float rate = .999;
  while (true) {
    clear();
    render_grid(grid);
    refresh();
    set_grid(grid);
    usleep(timer *= rate);
  }

	return 0;
}
