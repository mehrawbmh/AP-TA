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
    this->output = new Wire(0); // todo: creating output wire with id 0!!
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

    auto gateInputs = gate->getInputs();
    for (int j = 0; j < gateInputs.size(); j++) {
        this->wires[to_string(gateInputs[j]->getId())] = gateInputs[j];
    }

    this->gates[id] = gate;
}

const string& Module::getName() const
{
    return this->name;
}

void Module::connect(string firstId, string secondId)
{
    if (firstId.rfind("in", 0) == 0) {
        // first wire is input
        if (this->wires.find(firstId) != this->wires.end()) {
            this->wires[secondId] = this->wires[firstId];
        } else {
            throw NotFoundExcpetion("input not found");
        }
    } else if (firstId == "out") {
        this->wires[secondId] = this->output;
    } else if (secondId == "out") {
        this->wires[firstId] = this->output;
    }

    //todo: how to connect two normal wires?
    if (this->wires.find(firstId) != this->wires.end() && this->wires.find(secondId) != this->wires.end()) {
        this->wires[firstId] = this->wires[secondId];
    }
}

//todo move it
void Module::put(int wireId, bool value)
{
    string wireName = "in" + to_string(wireId);
    if (this->wires.find(wireName) == this->wires.end()) {
        throw NotFoundExcpetion("ID not found");
    }
    this->wires[wireName]->setVal(value);
}

Wire *Module::getOutput() const
{
    return this->output;
}
