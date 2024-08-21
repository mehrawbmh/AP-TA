#include "modules.hpp"
#include "exceptions.hpp"

Module::Module(const std::string & _name, int numInputs): name(_name)
{
    if (numInputs < 2) {
        throw BadInputException("module should have at least 2 arguments");
    }

    for (int i = 0; i < numInputs; i++) {
        string inputName = "in" + to_string(i);
        auto *wire = new Wire(i, Logic::X);

        this->wires[inputName] = wire;
        this->inputs.push_back(wire);
    }
}

Module::~Module()
{
    for (auto& gate : gates) {
        delete gate.second;
    }
    for (auto& wire : wires) {
        delete wire.second;
    }
}

Logic Module::resolve()
{
    return Logic::Z;
}

void Module::addGate(int id, Gate *gate)
{
    if (this->gates.find(id) != this->gates.end()) {
        throw BadInputException("duplicate ID");
    }

    this->gates[id] = gate;
}

string Module::getName() const
{
    return this->name;
}

void Module::put(int wireId, bool value)
{
    string wireName = "in" + to_string(wireId);
    if (this->wires.find(wireName) == this->wires.end()) {
        throw NotFoundExcpetion("ID not found");
    }
    this->wires[wireName]->setVal(value);
}
