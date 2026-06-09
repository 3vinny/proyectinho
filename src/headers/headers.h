#ifndef HEADERS_H
#define HEADERS_H

// --- Header central proyecto ---***

// --- Includes ---
#include <stdio.h>
#include <stdbool.h>

// --- Constantes ---
#define TARGET_FPS 60

// --- enums ---

typedef enum {
   SCREEN_MENU,
   SCREEN_PLAYING,
   SCREEN_GAMEOVER
}Screen;

// --- Estructura del input ---

typedef struct {
   bool teclaUp;
   bool teclaDown;
}InputState;

// --- Estructura Estado del juego ---
typedef struct {
   Screen screen; // Pantalla activa
   InputState input; // estado input
   int level; // Nivel actual
}GameState;

/*---- PROTOTIPOS DE FUNCIONES -------*/

void game_init(GameState *gs); // juego.c
void input_update(InputState *input); // input.c
void update(GameState *gs, InputState *input); // update.c
void render_gameview(GameState *gs); // render.c
void render_interfaz(GameState *gs); // interfaz.c
void assets_load(void); // assets.c
void config(GameState *gs); // config.c

#endif // Termina el header
