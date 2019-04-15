
#include "raylib.h"

struct paddle {
  void (*draw) (struct paddle*);  
  Vector2 pos;
  Vector2 size;
};

struct paddle* paddle_init(float x, float y);

void draw_paddle(struct paddle *p);
