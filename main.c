#include <SDL3/SDL_main.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#include "infra.h"
#include "game.h"

static GameWindow *gameWindow;
static Game *game;

void main_loop()
{
    get_input(gameWindow, game);
    update();
    draw(gameWindow, game);
    delay(gameWindow);

#ifdef __EMSCRIPTEN__
    if (!game->running)
        emscripten_cancel_main_loop();
#endif
}

int main(int argc, char *argv[])
{
    gameWindow = init_gamewindow();
    game = init(gameWindow);

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(main_loop, 0, 1);
#else
    while (game->running)
        main_loop();
    exit_game(gameWindow);
#endif
    return 0;
}
