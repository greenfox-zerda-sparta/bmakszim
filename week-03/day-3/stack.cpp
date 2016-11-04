#include <string>
#include <iostream>

using namespace std;

struct Stack {
  double* array;
  int length;
};

Stack* stack_construct(double input[], int size);

void stack_push(Stack& stack, double value);

double stack_pop(Stack& stack);

bool stack_is_empty(Stack& stack);

int main() {
  double array[] = {1, 2, 3, 4, 5};
  Stack* ptr = stack_construct(array, 5);
  for (int i = 0; i < 5; i++) {
    cout << *((ptr->array)+i) << endl;
  }
  cout << endl;

  stack_push(*ptr, 6);
  for (int i = 0; i < 6; i++) {
      cout << *((ptr->array)+i) << endl;
    }
  cout << endl;

  cout << stack_pop(*ptr) << endl << endl;

  cout << stack_is_empty(*ptr) << endl;

  delete[] ptr->array;
  delete ptr;
  return 0;
}

Stack* stack_construct(double input[], int size){
  Stack* s = new Stack;
  double* create_array = new double[size];
  for (int i = 0; i < size; i++) {
    create_array[i] = input[i];
  }
  s->array = create_array;
  s->length = size;
  return s;
}

void stack_push(Stack& stack, double value){
  double* new_array = new double[stack.length+1];
  for (int i = 0; i < stack.length; i++) {
    new_array[i] = *(stack.array+i);
  }
  new_array[stack.length] = value;
  stack.length += 1;
  delete[] stack.array;
  stack.array = new_array;
}

double stack_pop(Stack& stack) {
  double last = *(stack.array+(stack.length-1));
  double* new_array = new double[stack.length-1];
  for (int i = 0; i < stack.length-1; i++) {
    new_array[i] = *(stack.array+i);
  }
  stack.length -= 1;
  delete[] stack.array;
  stack.array = new_array;
  return last;
}

bool stack_is_empty(Stack& stack) {
  return stack.length == 0;
}
