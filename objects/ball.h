
#include "raylib.h"

struct ball {
  void (*draw) (struct ball*);  
  Vector2 pos;
};

struct ball* ball_init(float x, float y);

void draw_ball(struct ball *b);
