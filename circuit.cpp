#include "circuit.hpp"


Logic Circuit::print(int wireId)
{
    if (this->wires.find(wireId) == this->wires.end()) {
        throw NotFoundExcpetion("ID not found");
    }

    return this->wires[wireId]->getVal();
}
