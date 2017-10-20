//
// Created by Alexa on 20.10.2017.
//

#include "account.h"

Account::Account(std::string new_name, int new_balance) : name(new_name), balance(new_balance){
}

void Account::setBalance(int new_balance) {
    balance = new_balance;
}

std::string Account::getName() {
    return name;
}

int Account::getBalance() {
    return balance;
}
