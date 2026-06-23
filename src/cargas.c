// carga tiles desde archivo de 20x15
#include "headers.h"

void carga_Tiles(Game *game, const char *ruta)
{
   FILE *archivo = fopen("./data/hitbox.txt", "r");
   if (!archivo){
      printf("Error: No se pudo abrir el archivo -> %s\n", "./data/hitbox.txt");
   }

   char linea[tile_w + 2]; // 40 columnas + salto linea + EOF

   for(int i=0; i<tile_filas; i++)
   {
      // ta mejor q el fscanf mas safe segun
      if (fgets(linea, sizeof(linea), archivo) == NULL) break;
      for (int j=0; j<tile_cols; j++)
      {
         game->tiles[i][j].x_tiles = j * tile_w;
         game->tiles[i][j].y_tiles = i * tile_h;
         game->tiles[i][j].w_tiles = 2*tile_w;
         game->tiles[i][j].h_tiles = tile_h;
         game->tiles[i][j].activo = (linea[j] == '#'); 
         // cuando encuentre un # se activa booleano 
      }
   }

   fclose(archivo); //importante detalle
}
