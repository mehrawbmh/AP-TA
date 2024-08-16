#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>

#include "command_manager.hpp"
#include "and_gate.hpp"
#include "or_gate.hpp"
#include "not_gate.hpp"

#define COMMAND_PUT "put"
#define COMMAND_ADD "add"
#define COMMAND_CONNECT "connect"
#define COMMAND_NEW_MODULE "new_module"
#define COMMAND_END_MOODULE "end_module"

std::string trim(const std::string &str) {
    auto start = std::find_if_not(str.begin(), str.end(), [](unsigned char ch) {
        return std::isspace(ch);
    });

    auto end = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char ch) {
        return std::isspace(ch);
    }).base();

    return (start < end ? std::string(start, end) : std::string());
}

void CommandManager::handle(const string &input) {
    vector<string> words;
    stringstream iss(input);
    string token;

    while (getline(iss, token, ' ')) {
        if (trim(token).empty()) {
            continue;
        }
        words.push_back(token);
        cout << "token: " << token << endl;
    }

    if (words.size() <= 1) {
        cerr << "invalid input" << endl;
        return;
    }

    string command = words[0];

    try {
        auto * x = new OrGate({1,2}, 3);
        auto *a = new NorGate({6}, 4);
    
        cout << "created and gate" << endl;

        x->put(1, false);
        x->put(2, true);

        a->put(1, true);
        a->put(2, true);
        a->put(3, false);
        // x->put(8, false);
        
        Logic y = x->resolve();
        Logic z = a->resolve();

        cout << y << endl;
        cout << z << endl;
        
    } catch(const BadInputException &e) {
        cerr << e.what() << endl;
    }

    if (command == COMMAND_NEW_MODULE) {
        return;
    } else if (command == COMMAND_ADD) {
        return;
    }
}
