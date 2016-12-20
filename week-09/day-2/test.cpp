#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Account.h"
#include <utility>

void check_name(std::string);

std::pair<Account, Account> make_transfer(); //transformers

TEST_CASE ("Account created with a given name") {
  check_name("Joe Galamb");
  check_name("Bud Spencer");
}

TEST_CASE ("Account is created with 0 balance") {
  Account account("Joe Galamb");
  REQUIRE(account.get_balance() == Approx(0.0));
}

TEST_CASE ("Balance is filled by 50000") {
  Account account("Joe Galamb");
  account.top_up(50000);
  REQUIRE(account.get_balance() == Approx(50000.0));
}

TEST_CASE ("Check post transfer balances") {
  std::pair<Account, Account> post_transfer_accounts = make_transfer();
  REQUIRE(post_transfer_accounts.first.get_balance() == Approx(30000.0));
  REQUIRE(post_transfer_accounts.second.get_balance() == Approx(20000.0));
}

TEST_CASE("Check bond creation") {
  Account account("Béla");
  account.top_up(50000);
  account.create_bond(3000, 0.03);
  REQUIRE(account.get_balance() == 47000);
}

TEST_CASE("Check bond") {
  Account account("Béla");
  account.top_up(50000);
  account.create_bond(3000, 0.03);
  std::vector<Bond> b = account.get_bond();
  REQUIRE(!b.empty());
}

TEST_CASE("Empty bond return"){
  Account account("Terence");
  account.top_up(20000);
  std::vector<Bond> b = account.get_bond();
  REQUIRE(b.empty());
}

void check_name(std::string name) {
  Account account(name);
  REQUIRE(account.get_name() == name);
}

std::pair<Account, Account> make_transfer() {
  Account account_1("Joe Galamb");
  Account account_2("Jozsef Pidgeon");
  account_1.top_up(50000);
  account_1.transfer(account_2, 20000);
  return std::pair<Account, Account> {account_1, account_2};
}
