#include <stdio.h>
#include <stdlib.h>
#include "paddle.h"
#include "raylib.h"

void draw_paddle(struct paddle *p) {
  printf("DRAWING BALL\n");
  DrawRectangleV(p->pos, p->size, LIGHTGRAY); 
}

#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 100

struct paddle* paddle_init(float x, float y) {

  struct paddle *p;
  p = malloc(sizeof(struct paddle));

  /* Set the position provided*/
  p->pos.x = x;
  p->pos.y = y - (PADDLE_HEIGHT / 2.0);

  p->size.x = PADDLE_WIDTH;
  p->size.y = PADDLE_HEIGHT;
  
  p->draw = draw_paddle;
  return p;
}
