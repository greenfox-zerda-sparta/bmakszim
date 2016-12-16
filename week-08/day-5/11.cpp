#include <iostream>
#include <SDL.h>
#include "draw.hpp"

void cross(SDL_Renderer* &renderer, draw& d, int x, int y, int size);

int main(int argc, char ** argv) {
  int width = 729;
  int height = 729;
  bool quit = false;
  SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window = SDL_CreateWindow("SDL2 Fractal",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0); // háttér színe
  SDL_RenderClear(renderer);

//  while (!quit) {
    SDL_WaitEvent(&event);
//    if (event.type == SDL_QUIT) {
//      quit = true;
//      break;
//    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // rajzolás színe
    int x = 0;
    int y = 0;
    int size = 729;
    draw d(0, 0, 0);
    cross(renderer, d, x, y, size);
    /*for (int i = 0; i < 21; i++) {
      size = size / 3;
      cross(renderer, d, x+=size, y, size);
    }*/

    SDL_RenderPresent(renderer);
 // }
  system("pause");
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

void cross(SDL_Renderer* &renderer, draw& d, int x, int y, int size) {
  if (size > 3) {
    d.TurnTo(0);
    d.MoveTo(x, y + size/3);
    d.DrawBy(renderer, size);
    d.MoveTo(x, y + size/3*2);
    d.DrawBy(renderer, size);
    d.TurnTo(90);
    d.MoveTo(x + size/3, y);
    d.DrawBy(renderer, size);
    d.MoveTo(x + size/3*2, y);
    d.DrawBy(renderer, size);
    size = size / 3;
    cross(renderer, d, x+=size, y, size);
    cross(renderer, d, x+=size, y+=size, size);
    cross(renderer, d, x-=size, y+=size, size);
    cross(renderer, d, x-=size, y-=size, size);
  }
}
