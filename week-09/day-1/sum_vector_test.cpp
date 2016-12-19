#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "sum_vector.hpp"

TEST_CASE ("Testing sum_vector with multiple elements") {
  Sum_class asd;
  vector<int> v = {1, 2, 3, 4};
  REQUIRE (asd.sum_vector(v) == 10);
}

TEST_CASE ("Testing sum_vector with an empty list") {
  Sum_class asd;
  vector<int> v;
  REQUIRE (asd.sum_vector(v) == 0);
}

TEST_CASE ("Testing sum_vector with one element") {
  Sum_class asd;
  vector<int> v = {9};
  REQUIRE (asd.sum_vector(v) == 9);
}
