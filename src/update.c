#include "headers.h"

int chequea_tiles(Game *game, SDL_Rect *player_rect);

void game_Update(Game *game){
        
   int ancho_act = 0, alto_act = 0;
   int toca_xR = 1, toca_xL = 1; // flags
   int toca_yD = 1, toca_yU = 1;

   int i, j = 0;

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
   // el rojo
   SDL_Rect temp3 = {
      .x = game->x_colision,
      .y = game->y_colision,
      .w = game->w_colision,
      .h = game->h_colision
   };
        
   if (game->right == 1)
   {
      temp1.x += 1*(game->velocidad);
      if(!SDL_HasIntersection(&temp1, &temp2) && !SDL_HasIntersection(&temp1, &temp3) && !chequea_tiles(game, &temp1)){
         toca_xR = 0;
      } else {
         toca_xR = 1;
      }

      if (temp1.x <= 0 || temp1.x > ancho_act - (game->lado)) { 
         toca_xR = 1;
      }
   }

   if (game->left == 1)
   {
      temp1.x -= 1*(game->velocidad);
      if(!SDL_HasIntersection(&temp1, &temp2) && !SDL_HasIntersection(&temp1, &temp3) && !chequea_tiles(game, &temp1))
      {
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
      if(!SDL_HasIntersection(&temp1, &temp2) && !SDL_HasIntersection(&temp1, &temp3) && !chequea_tiles(game, &temp1))
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
      if(!SDL_HasIntersection(&temp1, &temp2) && !SDL_HasIntersection(&temp1, &temp3) && !chequea_tiles(game, &temp1)){
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

int chequea_tiles(Game *game, SDL_Rect *player_rect) {
    for (int i = 0; i < tile_filas; i++) {
        for (int j = 0; j < (int)tile_cols; j++) {
            if (game->tiles[i][j].activo) {
                SDL_Rect temp4 = {
                    .x = game->tiles[i][j].x_tiles,
                    .y = game->tiles[i][j].y_tiles,
                    .w = game->tiles[i][j].w_tiles,
                    .h = game->tiles[i][j].h_tiles
                };
                
                if (SDL_HasIntersection(player_rect, &temp4)) {
                    return 1; 
                }
            }
        }
    }
    return 0; 
}
