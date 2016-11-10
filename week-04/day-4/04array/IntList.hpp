#ifndef INT_LIST_HPP
#define INT_LIST_HPP

class IntList {
  private:
    int mLength;
  protected:
    void set_mLength();
  public:
    IntList();
    int get_mLength();
    virtual int get_index(int _i) = 0;
    virtual void append(int _a) = 0;
    virtual void insert(int _idx, int _a) = 0;
    virtual int getFirst() = 0;
    virtual int getLast() = 0;
    virtual bool isEmpty() = 0;
    virtual ~IntList();

};



#endif
