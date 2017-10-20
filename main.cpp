#include <iostream>
#include <fstream>
#include <sstream>
#include "account.h"
#include <map>
#include <unordered_map>
#include "Transaction.h"


int main() {
    std::string level_name = "../level2/level2-1";
    std::string filename = level_name;
    std::string out_filename = level_name+"_out";

    int count_account, count_transaction, balance, amount, overdraft;
    std::unordered_map<std::string, Account*> Accounts;
    unsigned long long time_stamp;
    std::map<long, Transaction*> transactions;


    // Init variables and read input file
    std::string input, accountname, sender, receiver, accountid;
    std::ifstream inFile;
    inFile.open(filename+".txt");

    std::getline(inFile, input, '\n');
    std::stringstream sstream(input);
    count_account = 0;
    sstream >> count_account;

    std::string accountnames[count_account];

    for (int i = 0; i < count_account; ++i) {
        std::getline(inFile, accountname, ' ');
        std::getline(inFile, accountid, ' ');
        std::getline(inFile, input, ' ');
        std::stringstream s(input);
        s >> balance;
        std::getline(inFile, input, '\n');
        std::stringstream ss(input);
        ss >> overdraft;
        Account *A = new Account(accountname, balance, overdraft, accountid);
        Accounts[accountid] = A;
        accountnames[i] = accountid;
    }

    std::getline(inFile, input, '\n');
    std::stringstream s(input);
    count_transaction = 0;
    s >> count_transaction;

    for (int i = 0; i < count_transaction; ++i) {
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
        if(Accounts[x.second->getSender()]->isValidID() && Accounts[x.second->getReceiver()]->isValidID() &&
                (Accounts[x.second->getSender()]->getBalance()-x.second->getAmount()) >= Accounts[x.second->getSender()]->getOverdraft()) {
            Accounts[x.second->getSender()]->setBalance(
                    Accounts[x.second->getSender()]->getBalance() - x.second->getAmount());
            Accounts[x.second->getReceiver()]->setBalance(
                    Accounts[x.second->getReceiver()]->getBalance() + x.second->getAmount());
        }
    }

    std::ofstream outFile;
    outFile.open(out_filename+".txt");

    outFile << count_account << endl;

    for(int i = 0; i < count_account; i++){
        if(Accounts[accountnames[i]]->isValidID()) {
            outFile << Accounts[accountnames[i]]->getName() << " " << Accounts[accountnames[i]]->getBalance() << endl;
        }
    }

    return 0;
}