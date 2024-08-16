#ifndef MODELSIM_BASE_MODULE_HPP
#define MODELSIM_BASE_MODULE_HPP

#include <vector>
#include "wire.hpp"
#include "exceptions.hpp"

using namespace std;

class BaseModule {
protected:
    vector<Wire*> inputs;
    Wire* output;
public:
    void put(int id, const bool &val);
    virtual Logic resolve() = 0;
};


#endif
