//
// Created by Alexa on 20.10.2017.
//
#include <string.h>
#include <iostream>

#ifndef INC_20171020_ACCOUNT_H
#define INC_20171020_ACCOUNT_H


class Account {
private:
    std::string name;
    int balance;

public:
    Account(std::string new_name, int new_balance);

    void setBalance(int balance);
    std::string getName();
    int getBalance();

};


#endif //INC_20171020_ACCOUNT_H
