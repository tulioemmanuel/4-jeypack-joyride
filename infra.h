#ifndef INFRA_H
#define INFRA_H

#include <SDL3/SDL.h>

#define WINDOW_W 800
#define WINDOW_H 600
#define WINDOW_TITLE "Jetpack Joyride"
#define FPS 60
#define PLAYER_W 10
#define PLAYER_H 100
#define GRAVITY 0.01
#define MAX_VY 1
#define MAX_AY 0.2
#define JUMP_ACCELERATION 1


typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Event event;
    long time;
    float delayTime;
} GameWindow;

GameWindow* init_gamewindow();
void delay(GameWindow* );
void exit_game(GameWindow*);

#endif
