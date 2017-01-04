#include <iostream>
#include <SDL.h>
#include <SDL_net.h>

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
  TCPsocket client = SDLNet_TCP_Open(&ip);
  char text[100];
  while (1) {
    SDLNet_TCP_Recv(client, text, 100);
    std::string str = text;
    if (str == "exit" || str == "quit") {
      break;
    }
    std::cout << text << std::endl;
  }
  SDLNet_TCP_Close(client);
  SDL_Quit();
  system("PAUSE");
}
