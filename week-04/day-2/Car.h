#ifndef CAR_H_
#define CAR_H_
#include <string>

using namespace std;


class Car {
  public:
    Car(string type, unsigned int km);
    void run(unsigned int km_run);
    unsigned int get_km();
  private:
    string type;
    unsigned int km;
};

#endif /* CAR_H_ */
