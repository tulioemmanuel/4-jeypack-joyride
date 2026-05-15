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
    player->pos.h = PLAYER_H;
    player->pos.w = PLAYER_W;
    player->pos.x = 0 + 100;
    player->pos.y = WINDOW_H - PLAYER_H - 100;
    player->vX = 0.0f;
    player->vY = 0.0f;
    player->aX = 0.0f;
    player->aY = 0.0f;
    player->isJumping = false;
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
        game->player->isJumping = true;
        game->player->aY = 0.5f;
        

    }
}

void update(Game *game)
{
    if (game->player->pos.y >= WINDOW_H - PLAYER_H)
    {
        game->player->pos.y = WINDOW_H - PLAYER_H;
        game->player->aY=0.0f;
    }
}

void draw(GameWindow *gameWindow, Game *game)
{
    SDL_SetRenderDrawColor(gameWindow->renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(gameWindow->renderer);

    SDL_SetRenderDrawColor(gameWindow->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(gameWindow->renderer, &game->player->pos);

    SDL_RenderPresent(gameWindow->renderer);
}
