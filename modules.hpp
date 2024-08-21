#ifndef MODELSIM_MODULE_HPP
#define MODELSIM_MODULE_HPP

#include "base_module.hpp"
#include "gate.hpp"
#include <map>

using namespace std;

class Module: public BaseModule {
private:
    map<int, Gate*> gates;
    string name;
    map<string, Wire*> wires;

public:
    Module(const std::string& _name, int numInputs);
    Module(const Module &other); // copy constructor
    ~Module();

    virtual Logic resolve() override;
    void addGate(int id, Gate* gate);
    const string &getName() const;
    void connect(string firstId, string secondId);
    void put(int wireId, bool value);
    Wire* getOutput() const;
};


#endif
