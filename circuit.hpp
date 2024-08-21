#ifndef MODELSIM_CIRCUIT_HPP
#define MODELSIM_CIRCUIT_HPP

#include "base_module.hpp"
#include <map>

// Main circuit of the program
class Circuit {
public:
    map<int, Wire*> wires;
    vector<BaseModule*> modules;

    Logic print(int wireId);
};


#endif
