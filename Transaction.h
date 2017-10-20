//
// Created by Alexa on 20.10.2017.
//

#ifndef INC_20171020_TRANSACTION_H
#define INC_20171020_TRANSACTION_H

#include <string.h>
#include <iostream>


using namespace std;

class Transaction {
private:
    std::string sender, receiver;
    int amount;
    long time;

public:
    Transaction(long create_time, std::string create_sender, std::string create_receiver, int create_amount);

    string getSender();

    string getReceiver();

    int getAmount();


};


#endif //INC_20171020_TRANSACTION_H
