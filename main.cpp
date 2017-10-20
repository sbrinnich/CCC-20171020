#include <iostream>
#include <fstream>
#include <sstream>
#include "account.h"
#include <map>
#include <unordered_map>
#include "Transaction.h"


int main() {

    std::string filename = "../level1/level1-4";
    std::string out_filename = "../level1/level1-4_out";


    int count_account, count_transaction, balance, amount;
    std::unordered_map<std::string, Account*> Accounts;
    unsigned long long time_stamp;
    std::map<long, Transaction*> transactions;


    // Init variables and read input file
    std::string input, accountname, sender, receiver;
    std::ifstream inFile;
    inFile.open(filename+".txt");

    std::getline(inFile, input, '\n');
    std::stringstream sstream(input);
    count_account = 0;
    sstream >> count_account;

    for (int i = 0; i < count_account; ++i) {
        std::getline(inFile, accountname, ' ');
        std::getline(inFile, input, '\n');
        std::stringstream s(input);
        s >> balance;
        Account *A = new Account(accountname, balance);
        Accounts[accountname] = A;
    }

    std::getline(inFile, input, '\n');
    std::stringstream s(input);
    count_transaction = 0;
    sstream >> count_transaction;

    for (int i = 0; i < count_account; ++i) {
        std::getline(inFile, sender, ' ');
        std::getline(inFile, receiver, ' ');
        std::getline(inFile, input, ' ');
        std::stringstream s(input);
        s >> amount;
        std::getline(inFile, input, '\n');
        std::stringstream ss(input);
        ss >> time_stamp;
        Transaction *A = new Transaction(time_stamp, sender, receiver, amount);
        transactions[time_stamp] = A;
    }

    for (auto const &x : transactions) {
        Accounts[x.second->getSender()]->setBalance(Accounts[x.second->getSender()]->getBalance()-x.second->getAmount());
        Accounts[x.second->getReceiver()]->setBalance(Accounts[x.second->getReceiver()]->getBalance()+x.second->getAmount());
    }

    std::ofstream outFile;
    outFile.open(out_filename+".txt");


    for(auto const &x : Accounts){
        outFile << x.first << " " << x.second->getBalance() <<endl;
    }

    return 0;
}