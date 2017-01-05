#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <string>
#include <conio.h>

using namespace std;

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_SocketSet set;
  set = SDLNet_AllocSocketSet(2);
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip);
  TCPsocket client;
  SDLNet_TCP_AddSocket(set, server);
  const char* text = "Alma";
  char textr[100];
  string str;
  while (1) {
    client = SDLNet_TCP_Accept(server);
    if (client) {
      SDLNet_TCP_AddSocket(set, client);
      while (1) {
        if (_kbhit() != 0) {
          getline(cin, str);
          text = str.c_str();
          SDLNet_TCP_Send(client, text, str.length()+1);
          if (str == "exit" || str == "quit") {
            break;
          }
        }
        int activeSockets = SDLNet_CheckSockets(set, 10);
        if (activeSockets != 0) {
          int gotMessage = SDLNet_SocketReady(client);
          if (gotMessage != 0) {
            SDLNet_TCP_Recv(client, textr, 100);
            str = textr;
            if (str == "exit" || str == "quit") {
              break;
            }
            std::cout << textr << std::endl;
          }
        }
      }
      SDLNet_TCP_Close(client);
      SDLNet_TCP_Close(server);
      SDLNet_FreeSocketSet(set);
    }
    if (str == "exit" || str == "quit") {
      break;
    }
  }
  SDL_Quit();
  system("PAUSE");
  return 0;
}
