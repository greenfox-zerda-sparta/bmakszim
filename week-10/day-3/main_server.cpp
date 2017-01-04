#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDLNet_Init();
    IPaddress ip;
    SDLNet_ResolveHost(&ip, NULL, 1234);
    TCPsocket server = SDLNet_TCP_Open(&ip);
    TCPsocket client;
    const char* text = "Alma";
    char textr[100];
    string str;
    while (1) {
      client = SDLNet_TCP_Accept(server);
      if (client) {
        while (1) {
          getline(cin, str);
          text = str.c_str();
          SDLNet_TCP_Send(client, text, str.length()+1);
          if (str == "exit" || str == "quit") {
            break;
          }
          SDLNet_TCP_Recv(client, textr, 100);
          std::cout << textr << std::endl;
        }
        SDLNet_TCP_Close(client);
      }
      if (str == "exit" || str == "quit") {
        break;
      }
    }
    SDL_Quit();
    system("PAUSE");
}
