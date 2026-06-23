#ifndef HEADERS_H
#define HEADERS_H

// --- Header central proyecto ---***

// --- Includes ---
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

typedef struct {
      SDL_Window *ventana;
      SDL_Renderer *renderer;
      SDL_Texture *texturaTexto;
      SDL_Texture *texturaTexto2;
      SDL_Texture *texturaImg;
      SDL_Surface *surfaceTexto;
      SDL_Surface *surfaceTexto2;
      TTF_Font *fuente;
      bool quit; // Flag
      int lado; // tam cuadrado
      int wText, hText;
      int x;
      int y;

      int velocidad; // multiplicador de velocidad en update.c (posicioens son int .'v)

      int x_ant; // variable que guarda la posicion anterior de mi cuadrado azul antes de entrar al evento
      int y_ant;

      int h_x; // hitbox
      int h_y; 
      int h_w;
      int h_h;

      int x_colision;
      int y_colision;
      int w_colision;
      int h_colision;

      int up;
      int down;
      int left;
      int right;

      struct
      {
         int x_tiles; // posicion mi rectangulo
         int y_tiles;
         int w_tiles; // alto y ancho mi rectangulo
         int h_tiles;
         bool activo;
      } tiles[tile_w][tile_h];


      bool Fullscreen;

}Game;

/*---- PROTOTIPOS DE FUNCIONES -------*/
bool SDL_Inicia(Game *game);  //config.c

bool cargarMedia(Game *game); //assets.c

void game_Limpieza(Game *game, int exitStatus); //config.c
void game_Main(Game *game, int exitStatus); //juego.c
void interfaz_Inicia(Game *game);  //interfaz.c

//void game_Menu(Game *game); //menu.c todavia no <-
void game_Input(Game *game); //input.c
void carga_Tiles(Game *game, const char *ruta); //cargas.c
void game_Update(Game *game); //update.c
void game_Render(Game *game); //render.c

SDL_Rect comprueba(Game *game); //cargas.c -> update.c -> render.c

#endif
