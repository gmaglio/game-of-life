#include <ncurses.h>
#include <unistd.h>
#include "./block.h"

int main() {
  initscr();

  char canvas[CANVAS_LINES][CANVAS_COL] = {
    { E, E, E, E, E },
    { E, E, B, E, E },
    { E, E, E, B, E },
    { E, B, B, B, E },
    { E, E, E, E, E },
    { E, E, E, E, E }
  };
  char grid[LINES][COLS];

  init_grid(grid);
  canvas_projection(canvas, grid);

  while (true) {
    clear();
    render_grid(grid);
    refresh();
    set_grid(grid);
    usleep(250000);
  }

	return 0;
}
