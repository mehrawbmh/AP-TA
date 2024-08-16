#ifndef MODELSIM_NOT_GATE_HPP
#define MODELSIM_NOT_GATE_HPP

#include "gate.hpp"

class NotGate: public Gate {
public:
    NotGate(vector<int> _inputs, int _output);
    Logic resolve() override;
};


#endif
