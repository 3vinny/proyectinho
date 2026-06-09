//#include "headers/headers.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <stdbool.h>

#define ANCHO 1024
#define ALTO 768

int main(int argc, char* argv[])
{
   // Inicializacion de SDL2
   if (!SDL_Init(SDL_INIT_VIDEO))
   {
      SDL_Log("No se puede iniciar %s\n", SDL_GetError());
      return 1;
   }
   // Inicia ttf
   if (!TTF_Init())
   {
      SDL_Log("No se puede iniciar ttf: %s\n", SDL_GetError());
      return 1;
   }

   SDL_SetAppMetadata("o cuadradinho", "0.01", "com.ejemplinho.ocuadradinho");

   SDL_Window *ventana = NULL;
   SDL_Renderer *renderer = NULL;
   bool corriendo = true;

   // Ventana y Display
   // Sin flags
   if(!SDL_CreateWindowAndRenderer("o cuadradinho", ANCHO, ALTO, SDL_WINDOW_RESIZABLE, &ventana, &renderer))
   {
      SDL_Log("NO se puede crear ventana: %s\n", SDL_GetError());
      TTF_Quit();
      SDL_Quit();
      return 1;
   }

   TTF_Font* fuente = TTF_OpenFont("/home/inasho/progra2/proyecto/arial.ttf", 24);

   if (!fuente)
   {
      SDL_Log("no se puede cargar ttf: %s\n", SDL_GetError());
   }

   SDL_Color Blanco = {255, 255, 255, 255};
   SDL_Surface* textoSurface = NULL;
   SDL_Texture* textoTexture = NULL;
   SDL_FRect textoDectRect = {0};

   if (fuente)
   {
      textoSurface = TTF_RenderText_Blended(fuente, "o cuadradinho maquavelicu kkk, Usa las flechas o AWSD para moverte", 0, Blanco);
      if (textoSurface){
         textoTexture = SDL_CreateTextureFromSurface(renderer, textoSurface);

         textoDectRect.x = 20.0f;
         textoDectRect.y = 20.0f;
         textoDectRect.w = (float)textoSurface->w;
         textoDectRect.h = (float)textoSurface->h;

         SDL_DestroySurface(textoSurface);
      }
   }

   SDL_FRect cuadradinho = {
      .x = 350.0f,
      .y = 250.0f,
      .w = 100.0f,
      .h = 100.0f
   };

   const float velocidad = 32.0f;

   SDL_Event evento;
   // Cola de eventos y timer
   
   while (corriendo)
   {
      while(SDL_PollEvent(&evento))
      {
         if (evento.type == SDL_EVENT_QUIT)
         {
            corriendo = false;
         }
         else if (evento.type == SDL_EVENT_KEY_DOWN)
         {
            switch(evento.key.key)
            {
               case SDLK_UP: // Tecla w= arriba
               case SDLK_W:
                  cuadradinho.y -= velocidad;
                  break;
               case SDLK_DOWN:
               case SDLK_S:
                  cuadradinho.y += velocidad;
                  break;
               case SDLK_LEFT:
               case SDLK_A:
                  cuadradinho.x -= velocidad;
                  break;
               case SDLK_RIGHT:
               case SDLK_D:
                  cuadradinho.x += velocidad;
                  break;
               case SDLK_ESCAPE:
                  corriendo = false;
                  break;
               default:
                  break;
            }
         }
      }

      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Color negro
      SDL_RenderClear(renderer);

      if(textoTexture)
      {
         SDL_RenderTexture(renderer, textoTexture, NULL, &textoDectRect);
      }

      SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Color azul
      SDL_RenderFillRect(renderer, &cuadradinho);

      SDL_RenderPresent(renderer);

      SDL_Delay(16); // 60FPS
   }
   // Iniciar estado juego (gamestate) y assets
   // game loop
   // Cierre y limpiar recursos
   if (textoTexture) SDL_DestroyTexture(textoTexture);
   if (fuente) TTF_CloseFont(fuente);

   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(ventana);
   TTF_Quit();
   SDL_Quit();

   return 0;
}
