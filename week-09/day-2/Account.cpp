#include "Account.h"

Account::Account(std::string name) {
  this->name = name;
}

std::string Account::get_name() {
  return name;
}

double Account::get_balance() {
  return balance;
}

void Account::top_up(double amount) {
  balance += amount;
}

void Account::decrease_balance(double amount) {
  balance -= amount;
}

void Account::transfer(Account& other,double amount) {
  decrease_balance(amount);
  other.top_up(amount);
}

void Account::create_bond(double amount, double interest_rate) {
  decrease_balance(amount);
  Bond bond;
  b.push_back(bond);
}

std::vector<Bond> Account::get_bond() {
  return b;
}
