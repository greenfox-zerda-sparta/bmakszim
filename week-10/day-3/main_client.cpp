#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
  TCPsocket client = SDLNet_TCP_Open(&ip);
  //TCPsocket server;
  const char* texts = "Alma";
  char text[100];
  while (1) {
    SDLNet_TCP_Recv(client, text, 100);
    std::string str = text;
    if (str == "exit" || str == "quit") {
      break;
    }
    std::cout << text << std::endl;
    getline(cin, str);
    texts = str.c_str();
    SDLNet_TCP_Send(client, texts, str.length()+1);
    if (str == "exit" || str == "quit") {
      break;
    }
  }
  SDLNet_TCP_Close(client);
  SDL_Quit();
  system("PAUSE");
}
