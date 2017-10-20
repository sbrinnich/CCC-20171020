//
// Created by Alexa on 20.10.2017.
//

#ifndef INC_20171020_TRANSACTION_H
#define INC_20171020_TRANSACTION_H

#include <string.h>
#include <iostream>
#include <map>
#include "InputElement.h"
#include "OutputElement.h"


using namespace std;

class Transaction {
private:
    std::string id;
    int num_inputs, num_outputs;
    unsigned long long time;
    std::map<std::string, InputElement*> inputs;
    std::map<std::string, OutputElement*> outputs;

public:
    Transaction(std::string id, unsigned long long time, int num_inputs, int num_outputs);
    void addInput(InputElement* in);
    void addOutput(OutputElement* out);

    std::string getID();
    unsigned long long getTime();
    int getNumInputs();
    int getNumOutputs();
    std::map<std::string, InputElement*> getInputs();
    std::map<std::string, OutputElement*> getOutputs();
    InputElement* getInput(std::string name);
    OutputElement* getOutput(std::string name);
};


#endif //INC_20171020_TRANSACTION_H
