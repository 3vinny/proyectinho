// Archivo update.c
#include "headers/headers.h"

// Este archivo impide que se salga de los bordesluego sera cambiado x un scroll

void game_Update(struct Game *game){
    int ancho_act, alto_act;
    int toca_x, toca_y; //estas son flagss

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
// w+h igualo h=w
    if (game->y > ((w_inicial/4)+(w_inicial/6)))
    {
        (game->y) = ((w_inicial/4)+(w_inicial/6));
    }

    if (game->x < (game->x_colision + game->w_colision) && (game->x + game->lado) > game->x_colision){
        toca_x = 1;
    }

    if (game->y < (game->y_colision + game->h_colision) && (game->y + game->lado) > game->y_colision){
        toca_y = 1;
    }

    if (toca_x == 1 && toca_y == 1){
        game->x = game->x_ant; // x es igual al anterior (mejor que la multiplicacion infinitesimal .v)
        game->y = game->y_ant;
        //game->x = game->x - (0.0001)*(game->x_colision - game->x);
        //game->y = game->y - (0.0001)*(game->y_colision - game->y);
    }
/*
// HITBOX = VENTANA aca
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
