

#include "raylib.h"
#include "gmodule.h"

#include "objects/ball.h"
#include "objects/paddle.h"

void draw_all();


int screenWidth = 0;
int screenHeight = 0;
GSList* objlist = NULL;

#define PADDLESPEED 4
#define MAXOBJECTS 256


void drawfunc (gpointer *data, gpointer *userdata) {

  struct tmp   {
       void (*draw) (struct tmp*);
       void *other;
  };

  struct tmp *t = (struct tmp*) data;
  t->draw(t);
  
}


/* Called once at the start / load */
int on_load(void) {
          
          screenWidth = 800;
          screenHeight = 450;

          struct ball *b = ball_init((float)screenWidth/2, (float)screenHeight/2);

          struct paddle *paddle_one = paddle_init(10,screenHeight/2.0);
          struct paddle *paddle_two = paddle_init(screenWidth - 40,screenHeight/2.0);

          objlist = g_slist_append(objlist, b);
          objlist = g_slist_append(objlist, paddle_one);
          objlist = g_slist_append(objlist, paddle_two);          

          InitWindow(screenWidth, screenHeight, "Murder Pong");
              
          SetTargetFPS(60);
}

int on_shutdown(void) 
{
     g_slist_free(objlist);
     CloseWindow();        // Close window and OpenGL context
}


          
/* called every iteration of the main loop */

int handle_input(void) {

  if (IsKeyDown(KEY_UP)) {
       struct paddle *p = g_slist_nth_data(objlist,1);
       p->pos.y -= PADDLESPEED;
  }

  if (IsKeyDown(KEY_DOWN)) {
       struct paddle *p = g_slist_nth_data(objlist,1);
       p->pos.y += PADDLESPEED;
  }
       
  if (IsKeyDown(KEY_RIGHT)) {
       printf("KEY RIGHT\n");


       struct ball *b;
       b = (struct ball*) g_slist_nth_data(objlist,0);
       b->pos.x += 2;
       printf("B POSITION: %2.6f\n", b->pos.x); 
       
  }
  

}

int main() {
        on_load();

        // Main game loop
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {

             handle_input();

             BeginDrawing();

             ClearBackground(RAYWHITE);

             DrawText("Oh man! You created your first window!", 190, 200, 20, LIGHTGRAY);

             g_slist_foreach(objlist, drawfunc, NULL);
             
             EndDrawing();
        }


        on_shutdown();
        

    return 0;
}

