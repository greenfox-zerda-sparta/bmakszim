#include <iostream>
#include <SDL.h>
#include <vector>
#include <time.h>
#include "draw.hpp"
#include "game-logic.hpp"

using namespace std;

void _draw(vector<vector<char>> v);

int main(int argc, char ** argv) {
  srand (time(NULL));
  Game game;

  /////////////////SDL///////////////

  int width = 570;
  int height = 570;
  bool quit = false;
  SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window = SDL_CreateWindow("SDL2 Amoba",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 220, 220, 255, 0);
  SDL_RenderClear(renderer);
  vector<vector<char>> v;
  while (!quit) {
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

    ///////////AI///////////////

    if (game.get_next() && (game.is_won() == false)) {
      int _x;
      int _y;
      for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
          game.can_i_win(j, i);
          game.is_danger_h(j, i);
          game.is_danger_v(j, i);
          game.is_danger_c1(j, i);
          game.is_danger_c2(j, i);
          game.make_4(j ,i);
        }
      }
      if (game.get_next()) {
        for (int i = 0; i < v.size(); i++) {
          for (int j = 0; j < v[i].size(); j++) {
            if (game.get_v(j, i) == '_' && game.get_next()) {
              game.set_v(j, i, 'O');
              if (game.can_be_danger()) {
                game.set_v(j, i, '_');
                game.set_cell(j, i);
              } else {
                game.set_v(j, i, '_');
              }
            }
          }
        }
      }
      if (game.get_next()) {
        for (int i = 0; i < v.size(); i++) {
          for (int j = 0; j < v[i].size(); j++) {
            game.make_3(j, i);
          }
        }
      }
      if (game.get_next()) {
        int c = 0;
        int r;
        for (int i = 0; i < v.size(); i++) {
          for (int j = 0; j < v[i].size(); j++) {
            if (game.get_v(j, i) == 'O') {
              c++;
            }
          }
        }
        if (c < 2) {
          for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
              if (game.get_v(j, i) == 'O') {
                do {
                  if (j > 0 && j < 18) {
                    r = (rand() % 3) - 1;
                    _x = (j+r);
                  } else if (j == 0) {
                    _x = (j+1);
                  } else if (j == 18) {
                    _x = (j-1);
                  }
                  _y = i;
                } while (v[_x][_y] != '_');
                game.set_cell(_x, _y);
              }
            }
          }
        } else {
          do {
            _x = rand() % 19;
            _y = rand() % 19;
          } while (v[_x][_y] != '_');
          game.set_cell(_x, _y);
        }
      }
    }

    ///////////AI///////////////

    if (event.type == SDL_MOUSEBUTTONDOWN) {
      int _x;
      int _y;
      SDL_GetMouseState(&_x, &_y);
      if (!game.is_won()) {
        game.set_cell((_x / (width / 19)), (_y / (height / 19)));
        _draw(game.get_vector());
      }
      cout << game.is_won() << endl;
    }
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
