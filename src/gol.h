#ifndef __GOL_H__
#define __GOL_H__

#include <ncurses.h>
#include "sprites.h"

#define B 'B' // (char)0x2588
#define E '\0'

char copy_grid(char src[LINES][COLS], char dest[LINES][COLS]);

char get_cell(char grid[LINES][COLS], ssize_t x, ssize_t y);

void render_grid(char grid[LINES][COLS]);

int is_occupied(char cell);

int count_neighbors(char grid[LINES][COLS], ssize_t x, ssize_t y);

void set_grid (char grid[LINES][COLS]);

void init_grid(char grid[LINES][COLS]);

void sprite_projection(
  const char canvas[SPRITE_LINES][SPRITE_COLS],
  char grid[LINES][COLS],
  int x_start,
  int y_start
);

#endif
