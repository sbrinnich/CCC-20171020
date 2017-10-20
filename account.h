//
// Created by Alexa on 20.10.2017.
//
#include <string.h>
#include <iostream>
#include <sstream>
#include <map>

#ifndef INC_20171020_ACCOUNT_H
#define INC_20171020_ACCOUNT_H


class Account {
private:
    std::string name;
    int balance;
    std::string accountid;
    int overdraft;

public:
    Account(std::string new_name, int new_balance, int overdr, std::string accid);

    void setBalance(int balance);
    std::string getName();
    int getBalance();
    int getOverdraft();
    std::string getAccountID();
    std::string getID();
    int getChecksum();
    bool isValidID();

};


#endif //INC_20171020_ACCOUNT_H
