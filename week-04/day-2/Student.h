#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>

using namespace std;

class Student {
  private:
	unsigned int* grades;
	unsigned int size;
  public:
	Student();
    void add_grade(unsigned int grade);
    float get_average();
    void show_grades();
};

#endif /* STUDENT_H_ */
