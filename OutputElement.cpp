//
// Created by Selina on 20.10.2017.
//

#include "OutputElement.h"

OutputElement::OutputElement(std::string owner, int amount) : owner(owner), amount(amount){
}

std::string OutputElement::getOwner() {
    return owner;
}

int OutputElement::getAmount() {
    return amount;
}