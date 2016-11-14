#ifndef REGGAE_HPP_
#define REGGAE_HPP_

#include <string>

using namespace std;

class Reggae: public Song {
private:
  string genre;
public:
  Reggae(string _a, string _t);
  string get_genre();
  bool rate(unsigned int _r);
};



#endif
