//
// Created by Selina on 20.10.2017.
//

#ifndef INC_20171020_INPUTELEMENT_H
#define INC_20171020_INPUTELEMENT_H

#include <iostream>


class InputElement {
private:
    std::string inID;
    std::string owner;
    int amount;

public:
    InputElement(std::string inID, std::string owner, int amount);
    std::string getInID();
    std::string getOwner();
    int getAmount();

};


#endif //INC_20171020_INPUTELEMENT_H
