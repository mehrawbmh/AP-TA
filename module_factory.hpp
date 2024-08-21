#ifndef MODELSIM_MODULE_FACTORY_HPP
#define MODELSIM_MODULE_FACTORY_HPP

#include "modules.hpp"

using namespace std;

class ModuleFactory {
private:
    vector<Module*> modules;
    Module* current = nullptr;
public:
    Module* createNew(string name, int inputCount);
    Module* getCurrentModule();
    void unsetCurrentModule();
};


#endif
