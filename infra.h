#ifndef INFRA_H
#define INFRA_H

#include <SDL3/SDL.h>

#define WINDOW_W 800
#define WINDOW_H 600
#define WINDOW_TITLE "Jetpack Joyride"
#define FPS 60
#define PLAYER_W 100
#define PLAYER_H 10


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
