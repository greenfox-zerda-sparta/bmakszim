#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <string>
#include <vector>
#include "draw.hpp"
#include "game-logic.hpp"

using namespace std;

void _draw(vector<vector<char>> v);

int main(int argc, char ** argv) {
  Game game;
  int width = 570;
  int height = 570;
  bool quit = false;
  SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING);

  /////////////////SDL_NET///////////////
  SDLNet_Init();
  IPaddress ip;
  SDLNet_SocketSet set;
  set = SDLNet_AllocSocketSet(2);
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip);
  TCPsocket client;
  SDLNet_TCP_AddSocket(set, server);
  /////////////////SDL_NET///////////////

  SDL_Window* window = SDL_CreateWindow("SDL2 Amoba",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 220, 220, 255, 0);
  SDL_RenderClear(renderer);
  vector<vector<char>> v;
  while (!quit) {
    ///////////SDLnet
    while(!quit) {
      client = SDLNet_TCP_Accept(server);
      if (client) {
        SDLNet_TCP_AddSocket(set, client);
        while (!quit) {
        //////////SDLnet
          v = game.get_vector();
          SDL_WaitEvent(&event);
          if (event.type == SDL_QUIT) {
            quit = true;
            break;
          }
          if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_q) {
              quit = true;
            }
          }
          if (game.get_next()) {
            if (event.type == SDL_MOUSEBUTTONDOWN) {
              int _x;
              int _y;
              SDL_GetMouseState(&_x, &_y);
              if (!game.is_won()) {
                game.set_cell((_x / (width / 19)), (_y / (height / 19)));
                ///////SDLnet
                int array[2] = {(_x / (width / 19)), (_y / (height / 19))};
                SDLNet_TCP_Send(client, &array, 2 * sizeof(int));
                ///////SDLnet
                _draw(game.get_vector());
              }
              cout << game.is_won() << endl;
            }
          } else {
            int _x;
            int _y;
            int array[2];
            /////SDLnet
            int activeSockets = SDLNet_CheckSockets(set, 10);
            if (activeSockets != 0) {
              int gotMessage = SDLNet_SocketReady(client);
              if (gotMessage != 0) {

                SDLNet_TCP_Recv(client, &array, 100);
            /////SDLnet
                _x = array[0];
                _y = array[1];
                if (!game.is_won()) {
                  game.set_cell(_x, _y);
                  _draw(game.get_vector());
                }
                cout << game.is_won() << endl;
              }
            }
          }
          v = game.get_vector();
          SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
          for (int i = 1; i < 19; i++) {
            SDL_RenderDrawLine(renderer, i * (width / 19), 0, i * (width / 19), height);
            SDL_RenderDrawLine(renderer, 0, i * (height / 19), width, i * (height / 19));
          }
          for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
              if (v[j][i] == 'X') {
                SDL_RenderDrawLine(renderer, i * (width / 19), j * (height / 19), (i + 1) * (width / 19), (j + 1) * (height / 19));
                SDL_RenderDrawLine(renderer, (i + 1) * (width / 19), j * (height / 19), i * (width / 19), (j + 1) * (height / 19));
              }
              if (v[j][i] == 'O') {
                SDL_RenderDrawLine(renderer, i * (width / 19) + 6, j * (height / 19) + 6, i * (width / 19) + 6, j * (height / 19) + 24);
                SDL_RenderDrawLine(renderer, i * (width / 19) + 24, j * (height / 19) + 6, i * (width / 19) + 24, j * (height / 19) + 24);
                SDL_RenderDrawLine(renderer, i * (width / 19) + 6, j * (height / 19) + 6, i * (width / 19) + 24, j * (height / 19) + 6);
                SDL_RenderDrawLine(renderer, i * (width / 19) + 6, j * (height / 19) + 24, i * (width / 19) + 24, j * (height / 19) + 24);
              }
              if (v[j][i] == 'X' || v[j][i] == 'O') {
                if (game.is_5in_lineh(j, i)) {
                  SDL_RenderDrawLine(renderer, i * (width / 19) + 15, j * (width / 19) + 15, i * (width / 19) + 15, (j + 4) * (width / 19) + 15);
                }
              }
              if (v[j][i] == 'X' || v[j][i] == 'O') {
                if (game.is_5in_linev(j, i)) {
                  SDL_RenderDrawLine(renderer, i * (width / 19) + 15, j * (width / 19) + 15, (i + 4) * (width / 19) + 15, j * (width / 19) + 15);
                }
              }
              if (v[j][i] == 'X' || v[j][i] == 'O') {
                if (game.is_5in_linec1(j, i)) {
                  SDL_RenderDrawLine(renderer, i * (width / 19) + 15, j * (width / 19) + 15, (i + 4) * (width / 19) + 15, (j + 4) * (width / 19) + 15);
                }
              }
              if (v[j][i] == 'X' || v[j][i] == 'O') {
                if (game.is_5in_linec2(j, i)) {
                  SDL_RenderDrawLine(renderer, i * (width / 19) + 15, j * (width / 19) + 15, (i - 4) * (width / 19) + 15, (j + 4) * (width / 19) + 15);
                }
              }
            }
          }
          SDL_RenderPresent(renderer);
        }
        SDLNet_TCP_Close(client);
      }
    }
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

void _draw(vector<vector<char>> v) {
  char c = 65;
  for (int i = 0; i < 19; i++) {
    cout << c++ << '|';
  }
  cout << endl;
  for (unsigned int i = 0; i < v.size(); i++) {
    for (unsigned int j = 0; j < v[i].size(); j++) {
      cout << v[i][j] << '|';
    }
    cout << i << endl;
  }
}
