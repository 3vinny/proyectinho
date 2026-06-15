// Archivo update.c
#include "headers/headers.h"

// Este archivo impide que se salga de los bordesluego sera cambiado x un scroll

void game_Update(struct Game * game){
    int ancho_act, alto_act;
    SDL_GetWindowSize(game->ventana, &ancho_act, &alto_act);
//(w_inicial/4), (h_inicial/6), (w_inicial/4), (h_inicial/2)
    if (game->x < (w_inicial/4))
    {
        (game->x) = (w_inicial/4);
    }

    if (game->y < (h_inicial/6))
    {
        (game->y) = (h_inicial/6);
    }

    if (game->x > (w_inicial/2))
    {
        (game->x) = (w_inicial/2);
    }

    if (game->y > ((h_inicial/6) + (h_inicial/2) ))
    {
        (game->y) = ((h_inicial/6) + (h_inicial/2));
    }
   
/*
    if (game->x < 0){
        (game->x) = 0;
    }
    if (game->y < 0){
        (game->y) = 0;
    }

    if (game->x + game->lado > ancho_act) {
        game->x = ancho_act - (game->lado);
    }

    if (game->y + game->lado > alto_act) {
        game->y = alto_act - (game->lado);
    }*/
}