#ifndef MODELSIM_COMMAND_MANAGER
#define MODELSIM_COMMAND_MANAGER

#include <string>

using namespace std;

class CommandManager {
public:
    void handle(const string &command);
};

#endif
