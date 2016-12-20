#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include <vector>

struct Bond {
  double amount;
  double interest_rate;
};

class Account {
private:
  std::string name;
  double balance;
  void decrease_balance(double);
  std::vector<Bond> b;
public:
  Account(std::string);
  std::string get_name();
  double get_balance();
  void top_up(double);
  void transfer(Account&, double);
  void create_bond(double, double);
  std::vector<Bond> get_bond();
};

#endif
