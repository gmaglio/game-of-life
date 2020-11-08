#include <ncurses.h>
#include <unistd.h>
#include "gol.h"
#include "sprites.h"

int main() {
  initscr();
  if (has_colors() == FALSE) {
    endwin();
    printf("Your terminal does not support color\n");
    return 1;
  }

  curs_set(0);

  start_color();
  init_pair(GRASS_PAIR, COLOR_RED, COLOR_BLACK);
  init_pair(WATER_PAIR, COLOR_CYAN, COLOR_BLUE);
  init_pair(MOUNTAIN_PAIR, COLOR_BLACK, COLOR_WHITE);
  init_pair(PLAYER_PAIR, COLOR_RED, COLOR_MAGENTA);

  char grid[LINES][COLS];

  init_grid(grid);
  sprite_projection(glider, grid, 20, 20);
  sprite_projection(lwss, grid, 10, 0);
  sprite_projection(pulsar, grid, 30, 0);

  attron(COLOR_PAIR(GRASS_PAIR));
  while (true) {
    clear();
    render_grid(grid);
    refresh();
    set_grid(grid);
    usleep(250000);
  }

	return 0;
}
