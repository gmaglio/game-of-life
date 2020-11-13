#ifndef COLOR_HELPERS_H
#define COLOR_HELPERS_H

int is_bold(int fg);
void init_colorpairs(void);
short curs_color(int fg);
int colornum(int fg, int bg);
void setcolor(int fg, int bg);
void unsetcolor(int fg, int bg);

#endif
