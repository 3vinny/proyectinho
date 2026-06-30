// archivo inputstate, tendra opcion de gamepad
#include "SDL_events.h"
#include "SDL_gamecontroller.h"
#include "headers.h"

void game_Input(Game *game)
{
   SDL_Event evento;
    
   while (SDL_PollEvent(&evento)) {
      if(evento.type == SDL_QUIT){
         game->quit = true;
      }

      if (evento.type == SDL_CONTROLLERBUTTONDOWN){
         printf("Se detecto presion mando: \n");
         switch(evento.cbutton.button)
         {
            case SDL_CONTROLLER_BUTTON_DPAD_UP: 
               printf("game up");
               game->up = 1;
               printf("abajo de game up");
               break;
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: 
               game->right = 1; 
               break;
            case SDL_CONTROLLER_BUTTON_DPAD_DOWN: 
               game->down = 1; 
               break;
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT: 
               game->left = 1; 
               break;
            default: game->up, game->down, game->left, game->right = 0; break;
         }
      }

      if (evento.type == SDL_CONTROLLERBUTTONUP){
         printf("se detecto levantamiento de mando: \n");
         switch(evento.cbutton.button)
         {
            case SDL_CONTROLLER_BUTTON_DPAD_UP: 
               game->up = 0;
               break;
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: 
               game->right = 0; 
               break;
            case SDL_CONTROLLER_BUTTON_DPAD_DOWN: 
               game->down = 0; 
               break;
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT: 
               game->left = 0; 
               break;
            default: game->up, game->down, game->left, game->right = 0; break;
         }
      }

      // CASO PALANCAS GAMEPAD
      if(evento.type == SDL_CONTROLLERAXISMOTION){
         switch(evento.caxis.axis){
            case SDL_CONTROLLER_AXIS_LEFTX:
               printf("Izquierda x\n");
               break;
            case SDL_CONTROLLER_AXIS_LEFTY:
               printf("Izquierda y\n");
               break;
            case SDL_CONTROLLER_AXIS_RIGHTX:
               printf("Derecha x\n");
               break;
            case SDL_CONTROLLER_AXIS_RIGHTY:
               printf("Derecha y\n");
               break;
            case SDL_CONTROLLER_AXIS_MAX:
               printf("Maximo\n");
               break;
            case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
               printf("Trigger left\n");
               break;
            case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
               printf("Trigger right\n");
               break;
            default:
               printf("Invalido o default\n");
               break;
         }
      }

      if(evento.type == SDL_KEYDOWN){
         switch(evento.key.keysym.sym)
         {
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
      }

      if(evento.type == SDL_KEYUP){
         switch(evento.key.keysym.sym){
            case SDLK_UP: case SDLK_w: game->up = 0; break;
            case SDLK_DOWN: case SDLK_s: game->down = 0; break;
            case SDLK_LEFT: case SDLK_a: game->left = 0; break;
            case SDLK_RIGHT: case SDLK_d: game->right = 0; break;
         }
      }
   }
}
