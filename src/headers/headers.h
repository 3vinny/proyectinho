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

struct Game {
      SDL_Window * ventana;
      SDL_Renderer * renderer;
      SDL_Texture * texturaTexto;
      SDL_Texture * texturaImg;
      SDL_Surface * surfaceTexto;
      TTF_Font * fuente;

      bool quit; // Flag
      int velocidad;
      int lado; // tam cuadrado
      int wText, hText;
      int x;
      int y;
      bool Fullscreen;

};

/*---- PROTOTIPOS DE FUNCIONES -------*/
bool SDL_Inicia(struct Game *game);  //config.c
bool cargarMedia(struct Game * game); //assets.c

void game_Limpieza(struct Game *game, int exitStatus); //config.c
void game_Main(struct Game *game, int exitStatus); //juego.c
void interfaz_Inicia(struct Game * game);  //interfaz.c

void game_Input(struct Game * game); //input.c
void game_Update(struct Game * game); //update.c
void game_Render(struct Game * game); //render.c

#endif
