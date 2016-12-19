#define CATCH_CONFIG_MAIN

#include "apple.hpp"
#include "catch.hpp"

TEST_CASE ("Testing getApple method") {
  Apple apple;
  REQUIRE (apple.getApple() == "apple");
}
