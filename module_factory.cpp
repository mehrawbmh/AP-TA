#include "module_factory.hpp"


Module* ModuleFactory::createNew(string name, int inputCount)
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

Module* ModuleFactory::getCurrentModule()
{
    return this->current;
}

void ModuleFactory::unsetCurrentModule()
{
    this->current = nullptr;
}
