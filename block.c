#include <ncurses.h>
#include <unistd.h>

#define B (char)0x2588
#define E '\0'
#define CANVAS_LINES 5 
#define CANVAS_COL 4

char get_cell(char grid[LINES][COLS], ssize_t x, ssize_t y) {
  return x < 0 || y < 0 || x > COLS || y > LINES ? E : grid[x][y];
}

void render_grid(char grid[LINES][COLS], ssize_t x, ssize_t y) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (grid[i][j] != E) {
        mvaddch(i, j, grid[i][j]); 
      }
    }
  }
}

int is_occupied(char cell) {
  if (cell == E) {
    return 0;
  }

  if (cell == B) {
    return 1;
  }
}

int count_neighbors(char grid[LINES][COLS], ssize_t x, ssize_t y) {
  int occupations[8] = {
    is_occupied(get_cell(grid, x - 1, y - 1)), // lower left
    is_occupied(get_cell(grid, x - 1, y + 1)), // upper left
    is_occupied(get_cell(grid, x + 1, y - 1)), // lower right
    is_occupied(get_cell(grid, x + 1, y + 1)), // upper right
    is_occupied(get_cell(grid, x, y + 1)), // up
    is_occupied(get_cell(grid, x, y - 1)), // down
    is_occupied(get_cell(grid, x - 1, y)), // left
    is_occupied(get_cell(grid, x + 1, y)) // right
  };

  int total = 0;
  for (int i = 0; i < 8; i++) {
    mvprintw(8 + i, 8, "occupation at %i: %i\n", i, occupations[i]);
    total = total + occupations[i];
  }

  return total;
}

void set_grid (char grid[LINES][COLS], ssize_t x, ssize_t y) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      int num_neighbors = count_neighbors(grid, i, j);

      if (grid[i][j] == B) {
        if (num_neighbors < 2 || num_neighbors > 3) {
          grid[i][j] = E;
          return;
        }
      }

      if (grid[i][j] == E) {
        if (num_neighbors == 3) {
          grid[i][j] = B;
          return;
        }
      }
    }
  }
}

int main() {
  initscr();

  char drawgrid[CANVAS_LINES][CANVAS_COL] = {
    { E, E, E, E },
    { E, E, B, E },
    { E, E, B, E },
    { E, E, B, E },
    { E, E, E, E }
  };

  char grid[LINES][COLS];

  // init grid
  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < COLS; j++) {
      grid[i][j] = E;
    }
  }

  for (int i = 0; i < CANVAS_LINES; i++) {
    for (int j = 0; j < CANVAS_COL; j++) {
      grid[i][j] = drawgrid[i][j];
    }
  }

  while (true) {
    clear();
    render_grid(grid, LINES, COLS);
    refresh();
    set_grid(grid, LINES, COLS);
    sleep(1);
  }

	return 0;
}
