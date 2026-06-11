#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define titulo "o cuadradinho en SDL2"
#define w_inicial 1366
#define h_inicial 768
#define delay 16

// Struct general
struct Game {
      SDL_Window * ventana;
      SDL_Renderer * renderer;
      SDL_Texture * texturaTexto;
      SDL_Surface * surfaceTexto;
      TTF_Font * fuente;
};

bool SDL_Inicia(struct Game *game);
void game_Limpieza(struct Game *game, int exitStatus);
void game_Main(struct Game *game, int exitStatus);

int main(int argc, char ** argv)
{

   struct Game game =  
   {
      .ventana = NULL,
      .renderer = NULL,
      .surfaceTexto = NULL,
      .texturaTexto = NULL,
      .fuente = NULL,
   };

   // llama a funcioon booleana inicia
   if(SDL_Inicia(&game)) 
   {
      game_Limpieza(&game, EXIT_FAILURE);
      exit(1);
   }
   
   // arranca juego y limpia
   game_Main(&game, EXIT_SUCCESS);
   game_Limpieza(&game, EXIT_SUCCESS);

   return 0;
}

void game_Main(struct Game *game, int exitStatus)
{
   bool quit = false; // Flag
   int velocidad = 15;
   int lado = 64; // tam cuadrado
   int wText, hText = 0;
   int x = 288;
   int y = 208;
   bool Fullscreen = false;

   SDL_Color colorTexto = { 255, 255, 255, 255 }; //Blanco y 255 de brillo
   game->surfaceTexto = TTF_RenderText_Solid(game->fuente, "Usa AWSD o flechas para moverte", colorTexto);
   game->texturaTexto = SDL_CreateTextureFromSurface(game->renderer, game->surfaceTexto);

   while (!quit){
      SDL_Event evento;
      SDL_WaitEvent(&(evento));
      
      switch(evento.type)
      {
         case SDL_QUIT:
            quit = true;
            break;

         case SDL_KEYDOWN:
            switch(evento.key.keysym.sym)
            {
               case SDLK_UP:
               case SDLK_w:
                  y -= velocidad;
                  break;
               case SDLK_DOWN:
               case SDLK_s:
                  y += velocidad;
                  break;
               case SDLK_LEFT:
               case SDLK_a:
                  x -= velocidad;
                  break;
               case SDLK_RIGHT:
               case SDLK_d:
                  x += velocidad;
                  break;
               case SDLK_F11:
                  Fullscreen = !Fullscreen; // se alterna
                  if (Fullscreen){
                     SDL_SetWindowFullscreen(game->ventana, SDL_WINDOW_FULLSCREEN_DESKTOP);
                  } else {
                     SDL_SetWindowFullscreen(game->ventana, 0);
                  }
                  break;
               case SDLK_ESCAPE:
                  game_Limpieza(game, EXIT_SUCCESS);
                  quit = true;
                  break;
               default:
                  break;
            }

         default:
            break;
      }

      int ancho_act, alto_act;
      SDL_GetWindowSize(game->ventana, &ancho_act, &alto_act);

      if (x < 0) x=0;
      if (y < 0) y=0;

      if (x + lado > ancho_act) {
         x = ancho_act - lado;
      }

      if (y + lado > alto_act) {
         y = alto_act - lado;
      }

   // graficos
   SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);

   SDL_RenderClear(game->renderer);

SDL_QueryTexture(game->texturaTexto, NULL, NULL, &wText, &hText);
   SDL_Rect textoRec = { 50, 50, wText, hText }; // posicion texto, ancho y alto
   SDL_RenderCopy(game->renderer, game->texturaTexto, NULL, &textoRec);

   SDL_SetRenderDrawColor(game->renderer, 0, 180, 255, 255); //rojo: 255, 0, 0 celeste: 0, 179, 255
   SDL_Rect Rectang = { x, y, lado, lado }; // responsable del rectangulo
   SDL_RenderFillRect(game->renderer, &Rectang); // d rellenarlo

   
   
   SDL_RenderPresent(game->renderer);
   }
}

void game_Limpieza(struct Game *game, int exitStatus)
{
   SDL_DestroyRenderer(game->renderer);
   SDL_DestroyTexture(game->texturaTexto);
   SDL_DestroyWindow(game->ventana);

   TTF_Quit();
   SDL_Quit();
   exit(exitStatus);
}

bool SDL_Inicia(struct Game *game)
{
   if (SDL_Init(SDL_INIT_EVERYTHING))
   {
      printf("Error al iniciar SDL: %s\n", SDL_GetError());
      return true;
   }
   
   // carga ventana
   game->ventana = SDL_CreateWindow(titulo, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_inicial, h_inicial, SDL_WINDOW_RESIZABLE);
   if (!game->ventana) {
      printf("Error al crear ventana: %s\n", SDL_GetError());
      return true;
   }

   // carga render
   game->renderer = SDL_CreateRenderer(game->ventana, -1, 0);
   if (!game->renderer) {
      printf("Error al crear renderer: %s\n", SDL_GetError());
      return true;
   }

   // Inicia ttf
   if (TTF_Init() == -1){
      printf("Error al cargar TTF: %s\n", TTF_GetError());
      return true;
   }

   // Carga de fuente ttf
   game->fuente = TTF_OpenFont("/home/inasho/progra2/proyecto/arial.ttf", 67);
   if (!(game->fuente))
   {
      printf("Error al cargar fuente .ttf: %s\n", TTF_GetError());
      return true;
   }

   return false; // es el caso bueno <-
}
