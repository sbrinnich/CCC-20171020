//
// Created by Alexa on 20.10.2017.
//

#include "Transaction.h"

Transaction::Transaction(std::string id, unsigned long long time, int num_inputs, int num_outputs) : id(id), time(time), num_inputs(num_inputs), num_outputs(num_outputs){

}

std::string Transaction::getID() {
    return id;
}

void Transaction::addInput(InputElement* in) {
    inputs[in->getOwner()] = in;
}

void Transaction::addOutput(OutputElement *out) {
    outputs[out->getOwner()] = out;
}

InputElement* Transaction::getInput(std::string name) {
    if(inputs.find(name) == inputs.end()){
        return nullptr;
    }
    return inputs[name];
}

OutputElement* Transaction::getOutput(std::string name) {
    if(outputs.find(name) == outputs.end()){
        return nullptr;
    }
    return outputs[name];
}

int Transaction::getNumInputs() {
    return num_inputs;
}

int Transaction::getNumOutputs() {
    return num_outputs;
}

std::map<std::string, InputElement*> Transaction::getInputs() {
    return inputs;
}

std::map<std::string, OutputElement*> Transaction::getOutputs() {
    return outputs;
}

unsigned long long Transaction::getTime() {
    return time;
}