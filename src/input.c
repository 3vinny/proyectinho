// archivo inputstate, tendra opcion de gamepad
#include "headers.h"

void game_Input(Game *game)
{
    // la x anterior igual a la x actual y la y lo mismo pura magia :v
    game->x_ant = game->x;
    game->y_ant = game->y;
    
   SDL_Event evento;
   while (SDL_PollEvent(&evento)) {
   switch(evento.type)
   {
      case SDL_QUIT:
         game->quit = true;
      break;

      case SDL_JOYAXISMOTION:
         if(evento.jaxis.axis == 0 || evento.jaxis.axis == 1)
         {
            printf("Movimiento de eje %d: %d\n", evento.jaxis.axis, evento.jaxis.axis);
         }
      break;
      /*-up=1
	-down=4
	-left=8
	-right=2
	-ninguno=0
       */
      case SDL_JOYHATMOTION:
         printf("boton HAT presionado: %d con valor: %d\n", evento.jhat.hat, evento.jhat.value);
         switch(evento.jhat.value)
         {
         case 0: game->up, game->down, game->left, game->right = 0; break;
            case 1: game->up = 1; break;
            case 2: game->right = 1; break;
            case 4: game->down = 1; break;
            case 8: game->left = 1; break;
         }
      break;

      case SDL_JOYBUTTONDOWN:
         printf("Boton %d presionado.\n", evento.jbutton.button);
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
