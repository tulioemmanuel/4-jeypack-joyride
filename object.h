#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL3/SDL.h>

typedef struct
{
    SDL_FRect pos;
    float vX;
    float vY;
    float aX;
    float aY;
    bool isJumping;

} Object;

#endif
