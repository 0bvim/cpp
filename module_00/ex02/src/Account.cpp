#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
  _nbAccounts++;
  _totalAmount += initial_deposit;
  _accountIndex = _nbAccounts;
}

Account::~Account(void) {}

void Account::makeDeposit(int deposit) {
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  std::cout << "Deposit of " << deposit << "made. New balance: " << _amount
            << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  if (withdrawal <= _amount) {
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "Withdrawal of " << withdrawal
              << " made. New balance: " << _amount << std::endl;
    return true;
  } else {
    std::cout << "Insufficient funds for withdraw." << std::endl;
    return false;
  }
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus() const {
  std::cout << "Account #" << _accountIndex << ": Balance = " << _amount
            << std::endl;
}

void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "Number of accounts: " << _nbAccounts << std::endl;
  std::cout << "Total amount: " << _totalAmount << std::endl;
  std::cout << "Total number of deposits: " << _totalNbDeposits << std::endl;
  std::cout << "Total number of withdrawals: " << _totalNbWithdrawals
            << std::endl;
}

void Account::_displayTimestamp() {
  std::time_t t = std::time(0);
  std::tm *now = std::localtime(&t);
  std::cout << "Current time: " << (now->tm_year + 1900) << '-'
            << (now->tm_mon + 1) << '-' << now->tm_mday << " " << now->tm_hour
            << ":" << now->tm_min << ":" << now->tm_sec << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }
