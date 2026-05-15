#ifndef GAME_H
#define GAME_H

#include "infra.h"
#include "object.h"

typedef struct
{
    Object *player;
    int running;

} Game;

Game* init(GameWindow *);
void init_stage();
Object* init_player();
void get_input(GameWindow *,Game*);
void update();
void draw(GameWindow *,Game*);

#endif