#include "not_gate.hpp"

NotGate::NotGate(vector<int> _inputs, int _output): Gate()
{
    if (_inputs.size() != 1) {
        throw BadInputException("incompatible inputs");
    }

    this->inputs.push_back(new Wire(_inputs[0]));
    this->output = new Wire(_output);
}

Logic NotGate::resolve()
{
    auto value = this->inputs[0]->getVal();
    if (value == Logic::X || value == Logic::Z) {
        return value;
    }

    this->output->setVal(value == Logic::ZERO);

    return (value == Logic::ONE) ? Logic::ZERO : Logic::ONE;
}
