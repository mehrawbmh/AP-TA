#include <iostream>
#include <algorithm>
#include <string>
#include "wire.hpp"
#include "command_manager.hpp"

using namespace std;

int main() {
    string input;
    auto *manager = new CommandManager();
    while (true) {
        getline(cin, input);
        if ((input == "EOF")) {
            break;;
        }
        manager->handle(input);
    }

    cout << "program ended." << endl;
    return 0;
}
