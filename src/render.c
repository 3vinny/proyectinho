// render.c
#include "headers/headers.h"
#include <SDL2/SDL_render.h>

void game_Render(struct Game *game)
{
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);

    SDL_RenderClear(game->renderer);

    // BACKGROUND
    SDL_RenderCopy(game->renderer, game->texturaImg, NULL, NULL);

    // TEXT
    SDL_QueryTexture(game->texturaTexto, NULL, NULL, &game->wText, &game->hText);
    SDL_Rect textoRec = { 50, 50, game->wText, game->hText }; // posicion texto, ancho y alto
    SDL_RenderCopy(game->renderer, game->texturaTexto, NULL, &textoRec);

    // TEXTO 2
    SDL_QueryTexture(game->texturaTexto2, NULL, NULL, &game->wText, &game->hText);
    SDL_Rect textoRec2 = { 500, 600, game->wText, game->hText };
    SDL_RenderCopy(game->renderer, game->texturaTexto2, NULL, &textoRec2);

    // RECTANGULO (hitbox)
    SDL_SetRenderDrawBlendMode(game->renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(game->renderer, 237, 237, 255, 125);
    SDL_Rect Hitbox = { (w_inicial/4), (h_inicial/6), (w_inicial/4)+(w_inicial/16), (w_inicial/4)+(w_inicial/16) };
    SDL_RenderFillRect(game->renderer, &Hitbox);

    // RECTANGULO (Movible)
    SDL_SetRenderDrawColor(game->renderer, 0, 180, 255, 255); //rojo: 255, 0, 0 celeste: 0, 179, 255
    SDL_Rect Rectang = { game->x, game->y, game->lado, game->lado };
    SDL_RenderFillRect(game->renderer, &Rectang);

    // RECTANGULO (Colision)
    SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255);
    SDL_Rect Rectang_Colision = { game->x_colision, game->y_colision, game->w_colision, game->h_colision };
    SDL_RenderFillRect(game->renderer, &Rectang_Colision);

    SDL_RenderPresent(game->renderer);
}
