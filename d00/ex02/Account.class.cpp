#include <iostream>
#include "Account.class.hpp"

Account::Account(int initial_deposit)
{
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _totalAmount += initial_deposit;
    std::cout << "[20150406_153629] " << "index:" << this->_accountIndex
              << ";amount:" << this->_amount << ";created\n";
    _nbAccounts += 1;
}

Account::~Account(void)
{
    std::cout << "[20150406_153629] " << "index:" << this->_accountIndex
              << ";amount:" << this->_amount << ";closed\n";
    _nbAccounts -= 1;
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
    std::cout << "[20150406_153629] accounts:" << _nbAccounts <<
              ";total:" << _totalAmount <<";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
    std::cout << "[20150406_153629] " << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    std::cout << "[20150406_153629] " << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    _totalNbDeposits += 1;
    _totalAmount += deposit;
    std::cout << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    std::cout << "[20150406_153629] " << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";withdrawal:";
    if (withdrawal >= this->_amount)
    {
        std::cout << "refused\n";
        return (false);
    }
    else
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        std::cout << withdrawal
                  << ";amount:" << this->_amount
                  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    }
    return (true);
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
