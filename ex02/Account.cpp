/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:49:22 by datran            #+#    #+#             */
/*   Updated: 2023/09/17 17:33:32 by datran           ###   ########.fr       */
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
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << \
    Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << \
    ";withdrawals:" << Account::_totalNbWithdrawals  << std::endl;
    
}

Account::Account(int initial_deposit) {
    Account::_displayTimestamp();
    _accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    _amount += initial_deposit;
    Account::_totalAmount += initial_deposit;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << \
    ";created" << std::endl;
}

void Account::makeDeposit(int deposit) {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << \
    ";deposit:" << deposit << ";amount:" << _amount + deposit << \
    ";nb_deposits:" << _nbDeposits + 1 << std::endl;
    _amount += deposit;
    _nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    if (withdrawal > _amount) {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << \
        ";withdrawal:refused" << std::endl;
        return false;
    }
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << \
    ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << \
    ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
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
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << \
    ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
    std::time_t currentTime = std::time(nullptr);
    std::tm *currentTm = std::localtime(&currentTime);
    char buffer[80];
    std::strftime(buffer, 80, "%Y%m%d_%H%M%S", currentTm);
    std::cout << "[" << buffer << "]" << " ";
}

Account::~Account(void){
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" <<_amount << ";closed" \
    << std::endl;
};
