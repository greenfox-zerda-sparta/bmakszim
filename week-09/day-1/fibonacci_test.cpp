#include "catch.hpp"
#include "fibonacci.hpp"

TEST_CASE("Testing fibonacci with 0") {
  Fibonacci fib;
  REQUIRE(fib.fib(0) == 0);
}

TEST_CASE("Testing fibonacci with 1") {
  Fibonacci fib;
  REQUIRE(fib.fib(1) == 1);
}

TEST_CASE("Testing fibonacci with 2") {
  Fibonacci fib;
  REQUIRE(fib.fib(2) == 1);
}

TEST_CASE("Testing fibonacci with 10") {
  Fibonacci fib;
  REQUIRE(fib.fib(10) == 55);
}
