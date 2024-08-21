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
    ~Module();

    virtual Logic resolve() override;
    void addGate(int id, Gate* gate);
    string getName() const;
    // void connect(int wireId, int gateId, int inputIndex);
    // void connectOutput(int wireId, int gateId);
    void put(int wireId, bool value);
    // void printResult();
};


#endif
