#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "account.h"
#include <map>
#include <unordered_map>
#include <vector>
#include "Transaction.h"


int main() {
    std::string level_name = "../level3/level3-eg";
    std::string filename = level_name;
    std::string out_filename = level_name+"_out";

    int count_transaction, amount, num_inputs, num_outputs;
    unsigned long long time_stamp;
    std::map<long, Transaction*> transactions;

    // Init variables and read input file
    std::string input, transid, inputid, owner;
    std::ifstream inFile;
    inFile.open(filename+".txt");

    std::getline(inFile, input, '\n');
    std::stringstream sstream(input);
    count_transaction = 0;
    sstream >> count_transaction;

    for (int i = 0; i < count_transaction; ++i) {
        std::getline(inFile, transid, ' ');
        std::getline(inFile, input, ' ');
        std::stringstream s(input);
        s >> num_inputs;
        std::vector<InputElement*> inputs;
        for(int j = 0; j < num_inputs; j++){
            std::getline(inFile, inputid, ' ');
            std::getline(inFile, owner, ' ');
            std::getline(inFile, input, ' ');
            std::stringstream ss(input);
            ss >> amount;
            inputs.push_back(new InputElement(inputid, owner, amount));
        }

        std::getline(inFile, input, ' ');
        std::stringstream sss(input);
        sss >> num_outputs;
        std::vector<OutputElement*> outputs;
        for(int j = 0; j < num_outputs; j++){
            std::getline(inFile, owner, ' ');
            std::getline(inFile, input, ' ');
            std::stringstream ss(input);
            ss >> amount;
            outputs.push_back(new OutputElement(owner, amount));
        }

        std::getline(inFile, input, '\n');
        std::stringstream ssss(input);
        ssss >> time_stamp;

        bool valid_transaction = true;

        int sum_in = 0, sum_out = 0;
        std::vector<std::string> out_owners;

        for(auto const &x : outputs){
            if(x->getAmount() <= 0){
                valid_transaction = false;
            }
            sum_out += x->getAmount();
            if(std::find(out_owners.begin(), out_owners.end(), x->getOwner()) != out_owners.end()){
                valid_transaction = false;
            }else{
                out_owners.push_back(x->getOwner());
            }
        }
        for(auto const &x : inputs){
            if(x->getAmount() <= 0){
                valid_transaction = false;
            }
            sum_in += x->getAmount();
        }

        if(sum_in != sum_out){
            valid_transaction = false;
        }

        for(auto const &x : inputs){
            if(x->getOwner() != "origin") {
                for (auto it = transactions.rbegin(); it != transactions.rend(); ++it) {
                    if (x->getOwner() == it->second->getOutput(x->getOwner())->getOwner()) {
                        if (x->getAmount() != it->second->getOutput(x->getOwner())->getAmount()) {
                            valid_transaction = false;
                            break;
                        }
                    }
                }
            }
        }

        std::cout << "Testy: " << count_transaction << endl;
        if(valid_transaction) {
            transactions[time_stamp] = new Transaction(transid, time_stamp, num_inputs, num_outputs);
            for (auto const &x : outputs) {
                transactions[time_stamp]->addOutput(x);
            }
            for (auto const &x : inputs) {
                transactions[time_stamp]->addInput(x);
            }
        }
    }

    std::ofstream outFile;
    outFile.open(out_filename+".txt");

    outFile << transactions.size() << std::endl;

    for (auto const &x : transactions) {
        outFile << x.second->getID() << " " << x.second->getNumInputs() << " ";
        for(auto const &z : x.second->getInputs()){
            outFile << z.second->getInID() << " " << z.second->getOwner() << " " << z.second->getAmount() << " ";
        }
        outFile << x.second->getNumOutputs() << " ";
        for(auto const &z : x.second->getOutputs()){
            outFile << z.second->getOwner() << " " << z.second->getAmount() << " ";
        }
        outFile << x.first << std::endl;
    }

    return 0;
}