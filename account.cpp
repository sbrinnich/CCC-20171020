//
// Created by Alexa on 20.10.2017.
//

#include "account.h"

Account::Account(std::string new_name, int new_balance, int overdr, std::string accid) :
        name(new_name), balance(new_balance), overdraft(overdr), accountid(accid){
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

int Account::getOverdraft() {
    return overdraft;
}

std::string Account::getAccountID() {
    return accountid;
}

std::string Account::getID() {
    return accountid.substr(5);
}

int Account::getChecksum() {
    std::stringstream s(accountid.substr(3,2));
    int x;
    s >> x;
    return x;
}

bool Account::isValidID() {
    std::map<char,int> uppers;
    std::map<char,int> lowers;

    std::string id = getID();
    char c;
    for(int i = 0; i < 10; i++){
        c = id.at(i);
        if(isupper(c)){
            if(uppers.find(c) == uppers.end() ){
                uppers[c] = 1;
            }else{
                uppers[c]++;
            }
        }else{
            if(lowers.find(c) == lowers.end() ){
                lowers[c] = 1;
            }else{
                lowers[c]++;
            }
        }
    }

    for(auto const &x : uppers){
        if(lowers.find(x.first) == lowers.end()){
            return false;
        }
        if(lowers[x.first] != x.second){
            return false;
        }
    }

    int sum = 0;
    for(int i = 0; i < 10; i++){
        c = id.at(i);
        sum += (int)c;
    }
    sum += 'C';
    sum += 'A';
    sum += 'T';
    sum += '0';
    sum += '0';

    sum = 98 - (sum % 97);
    if(getChecksum() == sum){
        return true;
    }

    return false;

}