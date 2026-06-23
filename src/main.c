#include "headers.h"

int main(int argc, char **argv)
{
   
   Game game = {
      .ventana = NULL,
      .joystick = NULL,
      .renderer = NULL,
      .surfaceTexto = NULL,
      .texturaTexto = NULL,
      .fuente = NULL,
      .quit = false,
      .velocidad = 1,
      .lado = 64,
      .x = 5,
      .y = 5,
      .x_ant = 208,
      .y_ant = 188,
      .h_x = w_inicial/6, 
      .h_y = h_inicial/6, 
      .h_w = 300, 
      .h_h = 300,
      .x_colision = 300,
      .y_colision = 300,
      .w_colision = 50,
      .h_colision = 25,
      .up = 0,
      .down = 0,
      .left = 0,
      .right = 0,
      .Fullscreen = false
   };
   
   fprintf(stderr, "----Inicializando SDL----\n");

   if(SDL_Inicia(&game)) 
   {
      game_Limpieza(&game, EXIT_FAILURE);
      exit(1);
   }

   SDL_Delay(delay);

   if (cargarMedia(&game))
   {
      game_Limpieza(&game, EXIT_FAILURE);
      exit(1);
   }

   carga_Tiles(&game);
   
   // arranca juego y limpia
   game_Main(&game, EXIT_SUCCESS);
   game_Limpieza(&game, EXIT_SUCCESS);

   return 0;
}
