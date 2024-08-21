#ifndef MODELSIM_WIRE_HPP
#define MODELSIM_WIRE_HPP

#include <string>
#include <iostream>

using namespace std;

enum class Logic {
    ZERO = 0,
    ONE = 1,
    X,
    Z,
};

std::ostream& operator<<(std::ostream& os, Logic logic);

class Wire {
private:
    Logic val;
    int id;
public:
    Wire(int _id, bool _val);
    Wire(int _id);
    Wire(int _id, Logic _val);
    
    void setId(int id);
    int getId();
    void setVal(bool val);
    Logic getVal();
};

#endif
