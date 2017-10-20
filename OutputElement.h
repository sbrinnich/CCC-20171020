//
// Created by Selina on 20.10.2017.
//

#ifndef INC_20171020_OUTPUTELEMENT_H
#define INC_20171020_OUTPUTELEMENT_H

#include <iostream>


class OutputElement {
private:
    std::string owner;
    int amount;

public:
    OutputElement(std::string owner, int amount);
    std::string getOwner();
    int getAmount();
};


#endif //INC_20171020_OUTPUTELEMENT_H
