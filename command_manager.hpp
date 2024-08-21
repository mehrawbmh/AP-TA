#ifndef MODELSIM_COMMAND_MANAGER
#define MODELSIM_COMMAND_MANAGER

#include <string>
#include "module_factory.hpp"
#include "circuit.hpp"

using namespace std;

class CommandManager {
private:
    ModuleFactory *factory;
    Circuit *circuit;
    vector<string> parseInput(const string &input);
public:
    CommandManager();
    void handle(const string &command);
};

#endif
