#ifndef MODELSIM_COMMAND_MANAGER
#define MODELSIM_COMMAND_MANAGER

#include <string>
#include "module_factory.hpp"

using namespace std;

class CommandManager {
private:
    ModuleFactory *factory;
    vector<string> parseInput(const string &input);
public:
    CommandManager();
    void handle(const string &command);
};

#endif
