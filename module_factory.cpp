#include "module_factory.hpp"
#include <cassert>
#include "gate.hpp"
#include "or_gate.hpp"
#include "and_gate.hpp"
#include "not_gate.hpp"


Module* ModuleFactory::createNew(const string &name, int inputCount)
{
    for (auto &module: this->modules) {
        if (module->getName() == name) {
            throw BadInputException("this module already exists");
        }
    }
    this->current = new Module(name, inputCount);;
    this->modules.push_back(this->current);

    return this->current;
}

Gate* ModuleFactory::createGate(int id, const string &type, vector<int> inputs, int output)
{
    Gate *gate;
    if (type == "or") {
        gate = new OrGate(inputs, output);
    } else if (type == "nor") {
        gate = new NorGate(inputs, output);
    } else if (type == "and") {
        gate = new AndGate(inputs, output);
    } else if (type == "nand") {
        gate = new NandGate(inputs, output);
    } else if (type == "not") {
        gate = new NotGate(inputs, output);
    } else if (type == "xor") {
        gate = new AndGate(inputs, output);
    } else {
        throw BadInputException("gate/module not found");
    }

    assert(this->getCurrentModule() != nullptr);
    this->getCurrentModule()->addGate(id , gate);

    return gate;
}

Module* ModuleFactory::getCurrentModule()
{
    return this->current;
}

void ModuleFactory::unsetCurrentModule()
{
    this->current = nullptr;
}
