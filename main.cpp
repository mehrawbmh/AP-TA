#include <iostream>
#include <algorithm>
#include <string>

#include "wire.hpp"
#include "command_manager.hpp"

#define END_INPUT_COMMAND "EOF"

using namespace std;

int main() {
    string input;
    auto *manager = new CommandManager();
    while (true) {
        getline(cin, input);
        if ((input == END_INPUT_COMMAND)) {
            break;
        }
        manager->handle(input);
    }

    return 0;
}
