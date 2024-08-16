#ifndef MODELSIM_OR_GATE_HPP
#define MODELSIM_OR_GATE_HPP

#include "gate.hpp"

class OrGate: public Gate {
public:
    OrGate(vector<int> _inputs, int _output): Gate(_inputs, _output) {}
    Logic resolve() override;
};

class NorGate: public Gate {
public:
    NorGate(vector<int> _inputs, int _output): Gate(_inputs, _output) {}
    Logic resolve() override;
};


#endif
