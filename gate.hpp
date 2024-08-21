#ifndef MODELSIM_GATE_HPP
#define MODELSIM_GATE_HPP

#include "base_module.hpp"

using namespace std;

//todo: implement xor gate from it
class Gate: public BaseModule {
public:
    Gate() = default;
    Gate(vector<int> inputs, int output);
    virtual ~Gate();
    virtual Logic resolve() = 0;
};

#endif
