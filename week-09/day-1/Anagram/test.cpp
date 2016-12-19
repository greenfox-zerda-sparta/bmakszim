#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "wordtoolbox.hpp"

TEST_CASE("testing countHowMany method with 'a'") {
  WordToolbox w("Tarzan's toenails");
  REQUIRE(w.countHowMany('a') == 3);
}

TEST_CASE("testing countHowMany method with 'T'") {
  WordToolbox w("Tarzan's toenails");
  REQUIRE(w.countHowMany('T') == 2);
}

TEST_CASE("testing countHowMany method with 't'") {
  WordToolbox w("Tarzan's toenails");
  REQUIRE(w.countHowMany('t') == 2);
}

TEST_CASE("testing countHowMany method with 'x'") {
  WordToolbox w("Tarzan's toenails");
  REQUIRE(w.countHowMany('x') == 0);
}

TEST_CASE("testing countHowMany method with ' '") {
  WordToolbox w("Tarzan's toenails");
  REQUIRE(w.countHowMany(' ') == 1);
}

TEST_CASE("testing countHowMany method with '\''") {
  WordToolbox w("Tarzan's toenails");
  REQUIRE(w.countHowMany('\'') == 1);
}

TEST_CASE("testing countHowMany with another string") {
  WordToolbox w("Tarzan's toenails. Me Tarzan, You Jane");
  REQUIRE(w.countHowMany('T') == 3);
}

TEST_CASE("testing isAnAnagram method with the lizard king:)") {
  WordToolbox w("Jim Morrison");
  REQUIRE(w.isAnAnagram("Mr. Mojo Risin'"));
}

TEST_CASE("testing isAnAnagram method with the 44") {
  WordToolbox w("Lewis Hamilton");
  REQUIRE(w.isAnAnagram("Am I shit? Well... NO!"));
}

TEST_CASE("testing isAnAnagram method with 'alma'1") {
  WordToolbox w("alma");
  REQUIRE_FALSE(w.isAnAnagram("almaa"));
}

TEST_CASE("testing isAnAnagram method with 'alma'2") {
  WordToolbox w("alma");
  REQUIRE_FALSE(w.isAnAnagram("alm"));
}

TEST_CASE("testing convertToLetters method") {
  WordToolbox w("");
  REQUIRE(w.convertToLetters(".h I'd E2t h3 2 :4(I$S{") == "hidethis");
}
