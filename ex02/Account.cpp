/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:49:22 by datran            #+#    #+#             */
/*   Updated: 2023/07/19 16:36:25 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
};

int Account::getTotalAmount(void) {
    return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "In GlobalBank, there are currently " << Account::_nbAccounts << " active accounts with a total amount of " << Account::_totalAmount << "$. A total of " << Account::_totalNbDeposits << " deposits and " << Account::_totalNbWithdrawals << " withdrawals were made" << std::endl;
}

Account::Account(int initial_deposit) {
    _accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    makeDeposit(initial_deposit);
}

void Account::makeDeposit(int deposit) {
    Account::_displayTimestamp();
    if (_nbDeposits == 0)
        std::cout << "Account[" << _accountIndex << "] made an initial deposit " << deposit << "$" << std::endl;
    else
        std::cout << "Account[" << _accountIndex << "] make a deposit " << deposit << "$" << std::endl;
    _amount += deposit;
    _nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    if (withdrawal > _amount) {
        std::cout << "Account[" << _accountIndex << "] dont have enough amount to withdrawn" << std::endl;
        return false;
    }
    std::cout << "Account [" << _accountIndex << "] make a withdrawal " << withdrawal << "$" << std::endl;
    _amount -= withdrawal;
    _nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    return true;
}

int Account::checkAmount(void) const {
    return _amount;
}

void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << "Account[" << _accountIndex << "] currently has " << _amount << "$. It made " << _nbDeposits << " deposits and " << _nbWithdrawals << " withdrawals" << std::endl;
}

void Account::_displayTimestamp(void) {
    std::time_t currentTime = std::time(nullptr);
    std::tm *currentTm = std::localtime(&currentTime);
    char buffer[80];
    std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", currentTm);
    std::cout << "Date and time: " << buffer << std::endl;
}

Account::~Account(void){};
