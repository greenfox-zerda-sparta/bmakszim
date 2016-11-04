#include <string>
#include <iostream>

using namespace std;

struct Stack {
  double* array;
  int length;
  int size_of_array;
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
  //cout << ptr->size_of_array << endl << ptr->length << endl;
  cout << endl;

  stack_push(*ptr, 6);
  stack_push(*ptr, 7);
  stack_push(*ptr, 8);
  stack_push(*ptr, 9);
  stack_push(*ptr, 10);
  stack_push(*ptr, 11);
  stack_push(*ptr, 12);
  stack_push(*ptr, 13);
  stack_push(*ptr, 14);
  stack_push(*ptr, 15);
  stack_push(*ptr, 16);
  stack_push(*ptr, 17);
  for (int i = 0; i < 17; i++) {
      cout << *((ptr->array)+i) << endl;
    }
  cout << endl;

  cout << stack_pop(*ptr) << endl;
  cout << stack_pop(*ptr) << endl;
  cout << stack_pop(*ptr) << endl;
  cout << stack_pop(*ptr) << endl;
  cout << stack_pop(*ptr) << endl;
  cout << stack_pop(*ptr) << endl;
  cout << stack_pop(*ptr) << endl << endl;
  stack_push(*ptr, 17);
  for (int i = 0; i < 11; i++) {
    cout << *((ptr->array)+i) << endl;
  }
  cout << endl;

  cout << ptr->size_of_array << endl << ptr->length << endl;

  cout << stack_is_empty(*ptr) << endl;

  delete[] ptr->array;
  delete ptr;
  return 0;
}

Stack* stack_construct(double input[], int size){
  int length = 2;
  while (length/2 < size) {
    length *= 2;
  }
  Stack* s = new Stack;
  double* create_array = new double[length];
  for (int i = 0; i < size; i++) {
    create_array[i] = input[i];
  }
  s->size_of_array = length;
  s->array = create_array;
  s->length = size;
  return s;
}

void stack_push(Stack& stack, double value){
  if (stack.length+1 > 0.8*stack.size_of_array) {
	stack.size_of_array *= 2;
    double* new_array = new double[stack.size_of_array];
    for (int i = 0; i < stack.length; i++) {
      new_array[i] = *(stack.array+i);
    }
    new_array[stack.length] = value;
    stack.length += 1;
    delete[] stack.array;
    stack.array = new_array;
  } else {
    *(stack.array+stack.length) = value;
    stack.length += 1;
  }
}

double stack_pop(Stack& stack) {
  double last = *(stack.array+(stack.length-1));
  stack.length -= 1;
  return last;
}

bool stack_is_empty(Stack& stack) {
  return stack.length == 0;
}
