// puro textoooooooo
#include "headers.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

void interfaz_Inicia(Game *game)
{
    SDL_Color colorTexto = { 255, 255, 255, 255 }; //Blanco y 255 de brillo
    game->surfaceTexto = TTF_RenderText_Solid(game->fuente, "Usa AWSD o flechas para moverte", colorTexto);
    game->texturaTexto = SDL_CreateTextureFromSurface(game->renderer, game->surfaceTexto);
    
    game->surfaceTexto2 = TTF_RenderText_Solid(game->fuente, "texto 2", colorTexto);
    game->texturaTexto2 = SDL_CreateTextureFromSurface(game->renderer, game->surfaceTexto2);
}
