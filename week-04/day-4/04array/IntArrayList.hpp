#ifndef INTARRAYLIST_HPP
#define INTARRAYLIST_HPP

class IntArrayList: public IntList {
  private:
	int mSize;
	int* array;

  public:
    IntArrayList();
    int get_index(int _i);
    void append(int _a);
    void insert(int _idx, int _a);
    int getFirst();
    int getLast();
    bool isEmpty();
    ~IntArrayList();
};





#endif
