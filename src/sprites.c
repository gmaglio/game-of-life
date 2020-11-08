#include "sprites.h"
#include "gol.h"

const char glider[SPRITE_LINES][SPRITE_COLS] = {
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, B, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, B, E, E, E, E, E, E, E, E, E },
  { E, B, B, B, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, B, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, B, E, E, E, E, E, E, E, E, E },
  { E, B, B, B, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
};

const char lwss[SPRITE_LINES][SPRITE_COLS] = {
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { B, E, E, B, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, B, E, E, E, E, E, E, E, E },
  { B, E, E, E, B, E, E, E, E, E, E, E, E },
  { E, B, B, B, B, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E }
};

const char pulsar[SPRITE_LINES][SPRITE_COLS] = {
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E },
  { E, E, E, E, E, E, E, E, E, E, E, E, E }
};
