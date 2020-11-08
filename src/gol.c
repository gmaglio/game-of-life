#include <ncurses.h>
#include "gol.h"
#include "sprites.h"

char copy_grid(char src[LINES][COLS], char dest[LINES][COLS]) {
  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < COLS; j++) {
      dest[i][j] = src[i][j];
    }
  }
}

char get_cell(char grid[LINES][COLS], ssize_t x, ssize_t y) {
  return x < 0 || y < 0 || x >= COLS || y >= LINES ? E : grid[x][y];
}

void render_grid(char grid[LINES][COLS]) {
  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < COLS; j++) {
      const char cell = grid[i][j];
      if (cell == B) {
        mvaddch(i, j, cell); 
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
    total = total + occupations[i];
  }
  return total;
}

void set_grid (char grid[LINES][COLS]) {
  char buff[LINES][COLS];
  copy_grid(grid, buff);

  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < COLS; j++) {
      int num_neighbors = count_neighbors(grid, i, j);

      if (grid[i][j] == B) {
        if (num_neighbors < 2 || num_neighbors > 3) {
          buff[i][j] = E;
          continue;
        }
      }

      if (grid[i][j] == E) {
        if (num_neighbors == 3) {
          buff[i][j] = B;
          continue;
        }
      }
    }
  }

  copy_grid(buff, grid);
}

void init_grid(char grid[LINES][COLS]) {
  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < COLS; j++) {
      grid[i][j] = E;
    }
  }
}

void sprite_projection(
  const char sprite[SPRITE_LINES][SPRITE_COLS],
  char grid[LINES][COLS],
  int x_start,
  int y_start
) {
  for (int i = 0; i < SPRITE_LINES; i++) {
    for (int j = 0; j < SPRITE_COLS; j++) {
      grid[i + y_start][j + x_start] = sprite[i][j];
    }
  }
}
