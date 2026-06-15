// render.c
#include "headers/headers.h"

void game_Render(struct Game * game)
{
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);

    SDL_RenderClear(game->renderer);

    // BACKGROUND
    SDL_RenderCopy(game->renderer, game->texturaImg, NULL, NULL);

    // TEXTO
    SDL_QueryTexture(game->texturaTexto, NULL, NULL, &game->wText, &game->hText);
    SDL_Rect textoRec = { 50, 50, game->wText, game->hText }; // posicion texto, ancho y alto
    SDL_RenderCopy(game->renderer, game->texturaTexto, NULL, &textoRec);

    // RECTANGULO (hitbox)
    SDL_SetRenderDrawBlendMode(game->renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(game->renderer, 237, 237, 255, 125);
    SDL_Rect Hitbox = { (w_inicial/4), (h_inicial/6), (w_inicial/4)+(w_inicial/16), (h_inicial/2)+(h_inicial/8) };
    SDL_RenderFillRect(game->renderer, &Hitbox);

    // RECTANGULO (Movible)
    SDL_SetRenderDrawColor(game->renderer, 0, 180, 255, 255); //rojo: 255, 0, 0 celeste: 0, 179, 255
    SDL_Rect Rectang = { game->x, game->y, game->lado, game->lado };
    SDL_RenderFillRect(game->renderer, &Rectang); // cangri
   
    SDL_RenderPresent(game->renderer);
}