#ifndef HEADERS_H
#define HEADERS_H

// --- Header central proyecto ---***

// --- Includes ---
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

// --- Constantes ---
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

// 

typedef struct {
   SDL_Renderer *renderer;
   SDL_Window *ventana;
} App;

/*---- PROTOTIPOS DE FUNCIONES -------*/

void game_init(GameState *gs); // juego.c
void input_update(InputState *input); // input.c
void update(GameState *gs, InputState *input); // update.c
void render_gameview(GameState *gs); // render.c
void render_interfaz(GameState *gs); // interfaz.c
void assets_load(void); // assets.c
void config(GameState *gs); // config.c

#endif // Termina el header
