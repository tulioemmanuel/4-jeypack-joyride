#include <stdlib.h>
#include "game.h"

Game *init(GameWindow *gameWindow)
{
    Game *game = malloc(sizeof(Game));
    game->running = true;
    game->player = init_player();
    return game;
}

void init_stage()
{
}

Object *init_player()
{
    Object *player = malloc(sizeof(Object));
    player->pos.h = 100;
    player->pos.w = 10;
    player->pos.x = 100;
    player->pos.y = 100;
    return player;
}

void get_input(GameWindow *gameWindow, Game *game)
{
    SDL_PollEvent(&gameWindow->event);
    const bool *key_states = SDL_GetKeyboardState(NULL);

    if (key_states[SDL_SCANCODE_ESCAPE])
    {
        game->running = false;
    }
    else if (key_states[SDL_SCANCODE_RIGHT])
    {
        game->player->pos.x += 1.0f;
    }
    else if (key_states[SDL_SCANCODE_LEFT])
    {
        game->player->pos.x -= 1.0f;
    }
    else if (key_states[SDL_SCANCODE_DOWN])
    {
        game->player->pos.y += 1.0f;
    }
    else if (key_states[SDL_SCANCODE_UP])
    {
        game->player->pos.y -= 1.0f;
    }
}

void update()
{
}

void draw(GameWindow *gameWindow, Game *game)
{
    SDL_SetRenderDrawColor(gameWindow->renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(gameWindow->renderer);

    SDL_SetRenderDrawColor(gameWindow->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(gameWindow->renderer, &game->player->pos);

    SDL_RenderPresent(gameWindow->renderer);
}
