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
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
  TCPsocket client = SDLNet_TCP_Open(&ip);
  SDLNet_TCP_AddSocket(set, client);
  const char* texts = "";
  char text[100];
  while (1) {
    std::string str = text;
    int activeSockets = SDLNet_CheckSockets(set, 10);
    if (activeSockets != 0) {
      int gotMessage = SDLNet_SocketReady(client);
      if (gotMessage != 0) {
        SDLNet_TCP_Recv(client, text, 100);
        if (str == "exit" || str == "quit") {
          break;
        }
        std::cout << text << std::endl;
      }
    }
    if (_kbhit() != 0) {
      getline(cin, str);
      texts = str.c_str();
      SDLNet_TCP_Send(client, texts, str.length()+1);
      if (str == "exit" || str == "quit") {
        break;
      }
    }
  }
  SDLNet_TCP_Close(client);
  SDLNet_FreeSocketSet(set);
  SDL_Quit();
  system("PAUSE");
  return 0;
}
