#include <stdio.h>
#include <stdlib.h>
#include "ball.h"
#include "raylib.h"



void draw_ball(struct ball *b) {
  printf("DRAWING BALL\n");
  DrawCircleV(b->pos, 10, MAROON);

}


struct ball* ball_init(float x, float y) {

  struct ball *b;
  b = malloc(sizeof(struct ball));

  /* Set the position provided*/
  b->pos.x = x;
  b->pos.y = y;

  /* Ugly af, set the draw method*/
  b->draw = draw_ball;
  return b;
}
