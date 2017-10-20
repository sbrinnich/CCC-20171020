//
// Created by Alexa on 20.10.2017.
//

#include "Transaction.h"

Transaction::Transaction(long create_time, std::string create_sender, std::string create_receiver, int create_amount) : time(create_time), sender(create_sender), receiver(create_receiver), amount(create_amount) {}

string Transaction::getSender() {
    return sender;
}

string Transaction::getReceiver() {
    return receiver;
}

int Transaction::getAmount() {
    return amount;
}
