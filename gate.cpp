#include "gate.hpp"

Gate::Gate(vector<int> _inputs, int _output): Gate()
{
    if (_inputs.size() < 2) {
        throw BadInputException("incompatible inputs");
        //todo: throw exception?
        return;
    } 

    for (size_t i = 0; i < _inputs.size(); i++) {
        this->inputs.push_back(new Wire(_inputs[i]));
    }
    this->output = new Wire(_output);
}
