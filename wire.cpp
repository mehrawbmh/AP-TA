#include "wire.hpp"

ostream& operator<<(ostream& os, Logic logic) {
    switch (logic) {
        case Logic::ONE:
            os << "1";
            break;
        case Logic::ZERO:
            os << "0";
            break;
        case Logic::X:
            os << "X";
            break;
        case Logic::Z:
            os << "Z";
            break;
        default:
            os << "Unknown";
            break;
    }
    return os;
}

Wire::Wire(int _id, bool _val): id(_id) {
    val = _val ? Logic::ONE : Logic::ZERO;
    cout << "wire " << this->id << "initiated." << endl;
}

Wire::Wire(int _id): id(_id)
{
    this->val = Logic::X;
}

void Wire::setId(int _id)
{
    this->id = _id;
}

int Wire::getId()
{
    return this->id;
}

void Wire::setVal(bool val)
{
    this->val = val ? Logic::ONE : Logic::ZERO;
}

Logic Wire::getVal()
{
    return this->val;
}
