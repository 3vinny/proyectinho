// Configuracion
// Volumen y muestra controles
#include "SDL_joystick.h"
#include "headers.h"

bool SDL_Inicia(Game *game)
{
   if (SDL_Init(SDL_INIT_EVERYTHING))
   {
      printf("Error al iniciar SDL: %s\n", SDL_GetError());
      return true;
   }

   
   int inicia_Imagen = IMG_Init(FLAGS_IMAGEN);
   if ((inicia_Imagen & FLAGS_IMAGEN) != FLAGS_IMAGEN) {
      printf("Error iniciando imagen SDL: %s\n", IMG_GetError());
   }

   int num_mandos = SDL_NumJoysticks();
   game->joystick = NULL;
   
   if (num_mandos < 1){
      printf("No se encontraron mandos conectados\n");
   } else {
      game->joystick = SDL_JoystickOpen(0);
      printf("%d joystick conectados.\n", num_mandos);
      printf("joystick abierto con exito: %s\n", SDL_JoystickName(game->joystick));
   }


   // carga ventana
   game->ventana = SDL_CreateWindow(titulo, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_inicial, h_inicial, 0);
   if (!game->ventana) {
      printf("Error al crear ventana: %s\n", SDL_GetError());
      return true;
   }

   // carga render
   game->renderer = SDL_CreateRenderer(game->ventana, -1, 0);
   if (!game->renderer) {
      printf("Error al crear renderer: %s\n", SDL_GetError());
      return true;
   }

   // Inicia ttf
   if (TTF_Init() == -1){
      printf("Error al cargar TTF: %s\n", TTF_GetError());
      return true;
   }

   // Carga de fuente ttf
   game->fuente = TTF_OpenFont("/home/inasho/progra2/proyecto/comicsans.ttf", 40);
   if (!(game->fuente))
   {
      printf("Error al cargar fuente .ttf: %s\n", TTF_GetError());
      return true;
   }

   return false;
}

void game_Limpieza(Game *game, int exitStatus)
{
   SDL_DestroyRenderer(game->renderer);
   SDL_DestroyTexture(game->texturaTexto);
   SDL_DestroyTexture(game->texturaImg);
   SDL_DestroyWindow(game->ventana);

   if(game->joystick != NULL)
   {
      SDL_JoystickClose(game->joystick);
   }

   IMG_Quit();
   TTF_Quit();
   SDL_Quit();
   exit(exitStatus);
}
