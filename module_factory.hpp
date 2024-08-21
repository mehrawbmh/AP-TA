#ifndef MODELSIM_MODULE_FACTORY_HPP
#define MODELSIM_MODULE_FACTORY_HPP

#include "modules.hpp"

using namespace std;

class ModuleFactory {
private:
    vector<Module*> modules;
    Module* current = nullptr;
public:
    Module* createNew(const string &name, int inputCount);
    Gate* createGate(int id, const string &type, vector<int> inputs, int output);
    Module* getCurrentModule();
    void unsetCurrentModule();
};


#endif
