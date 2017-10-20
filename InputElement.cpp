//
// Created by Selina on 20.10.2017.
//

#include "InputElement.h"

InputElement::InputElement(std::string inID, std::string owner, int amount) : inID(inID), owner(owner), amount(amount){
}

int InputElement::getAmount() {
    return amount;
}

std::string InputElement::getInID() {
    return inID;
}

std::string InputElement::getOwner() {
    return owner;
}