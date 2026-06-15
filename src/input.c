// archivo inputstate, tendra opcion de gamepad
#include "headers/headers.h"

void game_Input(struct Game * game)
{
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
    switch(evento.type)
    {
        case SDL_QUIT:
            game->quit = true;
            break;

        case SDL_KEYDOWN:
            switch(evento.key.keysym.sym)
            {
                case SDLK_UP: case SDLK_w: (game->y) -= game->velocidad; break;
                case SDLK_DOWN: case SDLK_s: (game->y) += game->velocidad; break;
                case SDLK_LEFT: case SDLK_a: (game->x) -= game->velocidad; break;
                case SDLK_RIGHT: case SDLK_d: (game->x) += game->velocidad; break;
                case SDLK_F11:
                    game->Fullscreen = !(game->Fullscreen); // se alterna
                    if (game->Fullscreen){
                        SDL_SetWindowFullscreen(game->ventana, SDL_WINDOW_FULLSCREEN_DESKTOP);
                    } else {
                        SDL_SetWindowFullscreen(game->ventana, 0);
                    }
                    break;
                case SDLK_ESCAPE:
                    game->quit = true;
                    break;
                default:
                break;
            }

         default:
            break;
        }    
    }
}