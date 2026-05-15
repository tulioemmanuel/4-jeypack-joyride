#include <stdlib.h>
#include "infra.h"

GameWindow *init_gamewindow()
{
    GameWindow *gameWindow = malloc(sizeof(GameWindow));
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
    }

    if (!SDL_CreateWindowAndRenderer(WINDOW_TITLE, WINDOW_W, WINDOW_H, SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS, &gameWindow->window, &gameWindow->renderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
    }

    gameWindow->time = SDL_GetTicks();
    gameWindow->delayTime = 1000.0f / FPS;

    return gameWindow;
}

void delay(GameWindow *gameWindow)
{
    long start = gameWindow->time;
    long current = SDL_GetTicks();
    long diff = current - start;
    if (diff < gameWindow->delayTime)
    {
        SDL_Delay(gameWindow->delayTime - diff);
    }
    gameWindow->time = current;
}

void exit_game(GameWindow *game)
{
    SDL_DestroyTexture(game->texture);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);

    SDL_Quit();
}