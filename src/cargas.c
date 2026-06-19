// carga tiles desde archivo de 32x16
#include "headers.h"
#include <stdio.h>

void game_Tiles(struct Game *game)
{
    //char tilemap
    for(int i=0; i<tiles_x; i++)
    {
        for (int j=0; j<tiles_y; j++)
        {
            game->tilemap[i][j] = 0;
        }
    }
}
