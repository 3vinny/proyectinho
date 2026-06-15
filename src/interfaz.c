// archivo interfaz grafica
// de momento es solo el texto
#include "headers/headers.h"

void interfaz_Inicia(struct Game * game)
{
    SDL_Color colorTexto = { 255, 255, 255, 255 }; //Blanco y 255 de brillo
    game->surfaceTexto = TTF_RenderText_Solid(game->fuente, "Usa AWSD o flechas para moverte", colorTexto);
    game->texturaTexto = SDL_CreateTextureFromSurface(game->renderer, game->surfaceTexto);
}