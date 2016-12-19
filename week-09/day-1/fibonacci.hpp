#ifndef FIBONACCI_HPP_
#define FIBONACCI_HPP_

class Fibonacci {
public:
  int fib(int n) {
    if (n > 1) {
      return fib(n - 1) + fib(n - 2);
    }
    if (n == 1) {
      return 1;
    }
    if (n == 0) {
      return 0;
    }
    else {
      return 0;
    }
  }
};

#endif
