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
#define COMMAND_PRINT "print"

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
    if (words.empty()) return;
    auto command = words[0];

    try {
        if (command == COMMAND_NEW_MODULE) {
            if (words.size() != 3) {
                cerr << "invalid inputs to create module" << endl;
                return;
            }
            assert(this->factory->getCurrentModule() == nullptr);
            this->factory->createNew(words[1], stoi(words[2]));

        } else if (command == COMMAND_END_MOODULE) {
            assert(this->factory->getCurrentModule() != nullptr);
            this->factory->unsetCurrentModule();
        
        } else if (command == COMMAND_CONNECT) {
            if (words.size() != 3) {
                cerr << "invalid inputs to conect wires" << endl;
                return;
            }
            if (this->factory->getCurrentModule() != nullptr) {
                this->factory->getCurrentModule()->connect(words[1], words[2]);
            } // todo write else

        } else if (command == COMMAND_ADD) {
            if (this->factory->getCurrentModule() != nullptr) {
                assert(words.size() >= 5);
                vector<int> inputs;
                for (int i=3; i < static_cast<int>(words.size()) - 1; i++) {
                    inputs.push_back(stoi(words[i]));
                }
                this->factory->createGate(stoi(words[2]), words[1], inputs, stoi(words[words.size() - 1]));
            } else {
                //todo: Add to main circuit
            }

        } else if (command == COMMAND_PUT) {
            if (this->factory->getCurrentModule() != nullptr) {
                cerr << "you can't put values in new_module mode!";
                return;
            }

        } else if (command == COMMAND_PRINT) {
            if (words.size() != 2) {
                cerr << "print must accepts one argument!" << endl;
                return;
            }
            cout << "printing...: \n";

        } else {
            cout << "NOt supported command:)\n";
            cout << this->factory->getCurrentModule()->getName() << endl;
            cout << this->factory->getCurrentModule()->getOutput()->getId() << endl;
            cout << this->factory->getCurrentModule()->getOutput()->getVal() << endl;
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
        // cout << "token: " << token << endl;
    }

    return words;
}
