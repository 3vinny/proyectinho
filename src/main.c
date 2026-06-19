#include "headers.h"

int main(int argc, char **argv)
{
   
   struct Game game = {
      .ventana = NULL,
      .renderer = NULL,
      .surfaceTexto = NULL,
      .texturaTexto = NULL,
      .fuente = NULL,
      .quit = false,
      .velocidad = 1,
      .lado = 64,
      .x = 208,
      .y = 188,
      .x_ant = 208,
      .y_ant = 188,
      .x_colision = 500,
      .y_colision = 270,
      .w_colision = 128,
      .h_colision = 64,
      .h_x = 500, 
      .h_y = 70, 
      .h_w = 300, 
      .h_h = 300,
      .up = 0,
      .down = 0,
      .left = 0,
      .right = 0,
      .mapa = NULL,
      .Fullscreen = false
   };
   
   if((game.mapa = fopen("./data/hitbox.txt", "r")) == NULL)
   {
      printf("Error al abrir el archivo");
   }
   
   fclose(game.mapa);
   fprintf(stderr, "----Inicializando SDL----\n");

   // .x 288, .y 208

   

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
   
   // arranca juego y limpia
   game_Main(&game, EXIT_SUCCESS);
   game_Limpieza(&game, EXIT_SUCCESS);

   return 0;
}
