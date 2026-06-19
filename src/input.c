// archivo inputstate, tendra opcion de gamepad
#include "headers.h"

void game_Input(struct Game *game)
{
    // la x anterior igual a la x actual y la y lo mismo pura magia :v
    game->x_ant = game->x;
    game->y_ant = game->y;
    
    // el evento d fortnite q agarra el caso quit o que una tecla sea presionada
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
                // podria cambiar velocidad por (game->y)--;
                case SDLK_UP: case SDLK_w: game->up = 1; break;
                case SDLK_DOWN: case SDLK_s: game->down = 1; break;
                case SDLK_LEFT: case SDLK_a: game->left = 1; break;
                case SDLK_RIGHT: case SDLK_d: game->right = 1; break;
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
        break;
        case SDL_KEYUP:
            switch(evento.key.keysym.sym){
                case SDLK_UP: case SDLK_w: game->up = 0; break;
                case SDLK_DOWN: case SDLK_s: game->down = 0; break;
                case SDLK_LEFT: case SDLK_a: game->left = 0; break;
                case SDLK_RIGHT: case SDLK_d: game->right = 0; break;
            }
         default:
            break;
    
        }    
    }
}
