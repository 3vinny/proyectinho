    // Archivo update.c: este se encarga de ver que mi cuadrado azul no toque
    // y que antes de renderizarse se cambie o no su posicion
    // pendiente ponerle velocidad (float)
    #include "headers.h"

    void game_Update(struct Game *game){
        
        int ancho_act = 0, alto_act = 0;
        int toca_xR = 1, toca_xL = 1; // flags
        int toca_yD = 1, toca_yU = 1;

        SDL_GetWindowSize(game->ventana, &ancho_act, &alto_act);

        SDL_Rect temp1 = {
            .x = game->x,
            .y = game->y,
            .w = game->lado,
            .h = game->lado
        };

        SDL_Rect temp2 = {
            .x = game->h_x,
            .y = game->h_y,
            .w = game->h_w,
            .h = game->h_h
        };

        // x_colision, y_colision, w_colision, h_colision
        SDL_Rect temp3 = {
            .x = game->x_colision,
            .y = game->y_colision,
            .w = game->w_colision,
            .h = game->h_colision
        };
        
        if (game->right == 1)
        {
            temp1.x += 1*(game->velocidad);
            if(!SDL_HasIntersection(&temp1, &temp2)){
                toca_xR = 0;
            } else {
                toca_xR = 1;
            }
            // aca es - posicion cuadrado porque no deberia tocar el borde ventana (no seria visible)
            if (temp1.x <= 0 || temp1.x > ancho_act - (game->lado)) { 
                toca_xR = 1;
            }
        }

        if (game->left == 1)
        {
            temp1.x -= 1*(game->velocidad);
            if(!SDL_HasIntersection(&temp1, &temp2)){
                toca_xL = 0;
            } else {
                toca_xL = 1;
            }

            if (temp1.x <= 0 || temp1.x > ancho_act - (game->lado)) { 
                toca_xL = 1; 
            }
        }
        
        if (game->down == 1)
        {
            temp1.y += 1*(game->velocidad);
            if(!SDL_HasIntersection(&temp1, &temp2))
            {
                toca_yD = 0;
            } else {
                toca_yD = 1;
            }

            if (temp1.y <= 0 || temp1.y > alto_act - (game->lado)) { 
                toca_yD = 1; 
            }
        }

        if (game->up == 1)
        {
            temp1.y -= 1*(game->velocidad);
            if(!SDL_HasIntersection(&temp1, &temp2)){
                toca_yU = 0;
            } else {
                toca_yU = 1;
            }

            if (temp1.y <= 0 || temp1.y > alto_act - (game->lado)) { 
                toca_yU = 1; 
            }
        }
        
        // posiciones son int
        if (toca_xR == 0 || toca_xL == 0){
            game->x = temp1.x;
        }

        if (toca_yD == 0 || toca_yU == 0){
            game->y = temp1.y;
        }
    }
