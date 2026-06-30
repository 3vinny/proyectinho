// Juego.c
// Inicio del juego
#include "headers.h"

void game_Main(Game *game, int exitStatus)
{
    interfaz_Inicia(game);


    while (!game->quit)
    {
        game_Input(game);
        //game_Menu(game);
        game_Update(game);
        game_Render(game);
    }
}
