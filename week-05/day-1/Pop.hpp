#ifndef POP_HPP_
#define POP_HPP_

class Pop: public Song {
private:
  string genre;
public:
  Pop(string _a, string _t);
  string get_genre();
  bool rate(unsigned int _r);
};

#endif
