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
  _accountIndex = _nbAccounts - 1;
}

Account::~Account(void) {}

void Account::makeDeposit(int deposit) {
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
	_displayTimestamp();
  std::cout << "Deposit of " << deposit << "made. New balance: " << _amount
            << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  if (withdrawal <= _amount) {
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
		_displayTimestamp();
    std::cout << "Withdrawal of " << withdrawal
              << " made. New balance: " << _amount << std::endl;
    return true;
  } else {
		_displayTimestamp();
    std::cout << "Insufficient funds for withdraw." << std::endl;
    return false;
  }
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << std::endl;
}

void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "Number of accounts: " << _nbAccounts << std::endl;
  _displayTimestamp();
  std::cout << "Total amount: " << _totalAmount << std::endl;
  _displayTimestamp();
  std::cout << "Total number of deposits: " << _totalNbDeposits << std::endl;
  _displayTimestamp();
  std::cout << "Total number of withdrawals: " << _totalNbWithdrawals
            << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", now);
    std::cout << "[" << buffer << "] ";
}

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }
