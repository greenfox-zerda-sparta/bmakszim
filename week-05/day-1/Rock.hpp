#ifndef ROCK_HPP_
#define ROCK_HPP_

class Rock: public Song {
private:
  string genre;
public:
  Rock(string _a, string _t);
  string get_genre();
  bool rate(unsigned int _r);
};

#endif
