#include "headers/headers.h"

int main(int argc, char **argv)
{
   fprintf(stderr, "arrancando main ---->>>>>\n");
   struct Game game = {
      .ventana = NULL,
      .renderer = NULL,
      .surfaceTexto = NULL,
      .texturaTexto = NULL,
      .fuente = NULL,
      .quit = false,
      .velocidad = 15,
      .lado = 64,
      .x = 208,
      .y = 188,
      .x_ant = 208,
      .y_ant = 188,
      .x_colision = 360,
      .y_colision = 270,
      .w_colision = 128,
      .h_colision = 64,
      .Fullscreen = false
   };
   
   // .x 288, .y 208
   if(SDL_Inicia(&game)) 
   {
      game_Limpieza(&game, EXIT_FAILURE);
      exit(1);
   }

   if (cargarMedia(&game))
   {
      game_Limpieza(&game, EXIT_FAILURE);
      exit(1);
   }
   
   // arranca juego y limpia
   game_Main(&game, EXIT_SUCCESS);
   game_Limpieza(&game, EXIT_SUCCESS);

   return 0;
}
