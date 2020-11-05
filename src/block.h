#ifndef __BLOCK_H__
#define __BLOCK_H__

#define B (char)0x2588

#define E '\0'

#define CANVAS_LINES 5 

#define CANVAS_COL 4

char copy_grid(char src[LINES][COLS], char dest[LINES][COLS]);

char get_cell(char grid[LINES][COLS], ssize_t x, ssize_t y);

void render_grid(char grid[LINES][COLS]);

int is_occupied(char cell);

int count_neighbors(char grid[LINES][COLS], ssize_t x, ssize_t y);

void set_grid (char grid[LINES][COLS]);

void init_grid(char grid[LINES][COLS]);

void canvas_projection(
  char canvas[CANVAS_LINES][CANVAS_COL],
  char grid[LINES][COLS]
);

#endif
