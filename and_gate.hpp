#ifndef MODELSIM_AND_GATE_HPP
#define MODELSIM_AND_GATE_HPP

#include "gate.hpp"

class AndGate: public Gate {
public:
    AndGate(vector<int> _inputs, int _output): Gate(_inputs, _output) {}
    Logic resolve() override;
};

class NandGate: public Gate {
public:
    NandGate(vector<int> _inputs, int _output): Gate(_inputs, _output) {}
    Logic resolve() override;
};

#endif
