#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <cassert>

#include "command_manager.hpp"
#include "and_gate.hpp"
#include "or_gate.hpp"
#include "not_gate.hpp"

#define COMMAND_PUT "put"
#define COMMAND_ADD "add"
#define COMMAND_CONNECT "connect"
#define COMMAND_NEW_MODULE "new_module"
#define COMMAND_END_MOODULE "end_module"

CommandManager::CommandManager()
{
    this->factory = new ModuleFactory();
}

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
    vector<string> words = this->parseInput(input);
    if (words.size() <= 1) {
        cerr << "invalid input" << endl;
        return;
    }

    auto command = words[0];

    try {
        if (command == COMMAND_NEW_MODULE) {
            if (words.size() != 3) {
                cerr << "invalid inputs to create module" << endl;
                return;
            } 
            assert(factory->getCurrentModule() == nullptr);
            this->factory->createNew(words[1], stoi(words[2]));

        } else if (command == COMMAND_END_MOODULE) {
            this->factory->unsetCurrentModule();
        } else if (command == COMMAND_ADD) {
            return;
        }

    } catch(const BadInputException &e) {
        cerr << e.what() << endl;
    } catch(const NotFoundExcpetion &e2) {
        cerr << e2.what() << endl;
    }
}

vector<string> CommandManager::parseInput(const string &input)
{
    stringstream iss(input);
    string token;
    vector<string> words;

    while (getline(iss, token, ' ')) {
        if (trim(token).empty()) {
            continue;
        }
        words.push_back(token);
        cout << "token: " << token << endl;
    }

    return words;
}
