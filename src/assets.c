// archivo para los assets
// d momento solo carga el fondo
#include "headers.h"

bool cargarMedia(struct Game *game)
{
    game->texturaImg = IMG_LoadTexture(game->renderer, "/home/inasho/progra2/proyecto/assets/bg/bg.png");
    if (!game->texturaImg) {
        printf("Error iniciando textura: %s\n", IMG_GetError());
        return true;
    }
    return false;
}
