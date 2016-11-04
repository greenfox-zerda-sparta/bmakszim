#include <string>
#include <iostream>

using namespace std;

struct Vector {
  double* array;
  int size;
};

Vector* vector_construct(double input[], int size);

double vector_at(Vector& v, unsigned int index);

void vector_insert(Vector& v, unsigned int index, double value);

unsigned int vector_find(Vector& v, double value);

void vector_remove(Vector& v, unsigned int index);

Vector* vector_concat(Vector& v1, Vector v2);

int main() {
  double array[] = {1, 2, 3, 4, 5};
  Vector* ptr = vector_construct(array, 5);
  for (int i = 0; i < 5; i++) {
    cout << *((ptr->array)+i) << endl;
  }
  cout << endl;

  cout << "At index 5: " << vector_at(*ptr, 5) << endl;
  cout << endl;

  vector_insert(*ptr, 2, 10);
  for (int i = 0; i < 6; i++) {
    cout << *((ptr->array)+i) << endl;
  }
  cout << endl;

  cout << "Value 10 found at index: " << vector_find(*ptr, 10) << endl;
  cout << endl;

  vector_remove(*ptr, 2);
  for (int i = 0; i < 5; i++) {
    cout << *((ptr->array)+i) << endl;
  }
  cout << endl;

  double array1[] = {6, 7, 8};
  Vector* ptr1 = vector_construct(array1, 3);
  for (int i = 0; i < 3; i++) {
    cout << *((ptr1->array)+i) << endl;
  }
  cout << endl;

  double array2[] = {9, 10};
  Vector* ptr2 = vector_construct(array2, 2);
  for (int i = 0; i < 2; i++) {
    cout << *((ptr2->array)+i) << endl;
  }
  cout << endl;

  Vector* ptr3 = vector_concat(*ptr1, *ptr2);
  for (int i = 0; i < 5; i++) {
    cout << *((ptr3->array)+i) << endl;
  }
  cout << endl;

  delete[] ptr3->array;
  delete ptr3;
  delete[] ptr1->array;
  delete ptr1;
  delete[] ptr2->array;
  delete ptr2;
  delete[] ptr->array;
  delete ptr;
  return 0;
}

Vector* vector_construct(double input[], int length) {
  Vector* v = new Vector;
  double* new_array = new double[length];
  for (int i = 0; i < length; i++) {
    new_array[i] = input[i];
  }
  v->array = new_array;
  v->size = length;
  return v;
}

double vector_at(Vector& v, unsigned int index) {
  if ((int) index >= v.size) {
    return 0;
  } else {
    return v.array[index];
  }
}

void vector_insert(Vector& v, unsigned int index, double value) {
  double* new_array = new double[v.size+1];
  for (int i = 0; i < (int) index; i++) {
    new_array[i] = *(v.array+i);
  }
  new_array[index] = value;
  for (int i = index+1; i < v.size+1; i++) {
    new_array[i] = *(v.array+i-1);
  }
  v.size +=1;
  delete[] v.array;
  v.array = new_array;
}

unsigned int vector_find(Vector& v, double value) {
  for (int i = 0; i < v.size; i++) {
    if (*(v.array+i) == value) {
      return i;
    }
  }
}

void vector_remove(Vector& v, unsigned int index) {
  double* new_array = new double[v.size-1];
  for (int i = 0; i < (int) index; i++) {
    new_array[i] = *(v.array+i);
  }
  for (int i = index; i < v.size-1; i++) {
    new_array[i] = *(v.array+i+1);
  }
  v.size -=1;
  delete[] v.array;
  v.array = new_array;
}

Vector* vector_concat(Vector& v1, Vector v2) {
  Vector* v = new Vector;
  double* new_array = new double[v1.size + v2.size];
  for (int i = 0; i < v1.size; i++) {
    new_array[i] = *(v1.array+i);
  }
  for (int i = v1.size; i < v1.size + v2.size; i++) {
    new_array[i] = *(v2.array++);
  }
  v->array = new_array;
  v->size = v1.size + v2.size;
  return v;
}
