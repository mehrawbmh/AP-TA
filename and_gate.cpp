#include "and_gate.hpp"
#include "wire.hpp"

Logic AndGate::resolve()
{
    cout << "resolving and gate..." << endl;

    // cout << this->inputs[0]->getId() << ": " << this->inputs[0]->getVal() << endl;
    // cout << this->inputs[1]->getId() << ": " << this->inputs[1]->getVal() << endl;

    bool hasX = any_of(
        this->inputs.begin(),
        this->inputs.end(),
        [] (Wire* x) {
            return x->getVal() == Logic::X;
        }
    );

    bool allZ = all_of(
        this->inputs.begin(),
        this->inputs.end(),
        [] (Wire* x) {
            return x->getVal() == Logic::Z;
        }
    );
    
    bool has0 = any_of(
        this->inputs.begin(),
        this->inputs.end(),
        [] (Wire* x) {
            return x->getVal() == Logic::ZERO;
        }
    );

    this->output->setVal(!has0);

    return hasX ?
        Logic::X :
        (allZ ? Logic::Z :(has0 ? Logic::ZERO : Logic::ONE));
}

Logic NandGate::resolve()
{
    cout << "resolving nand gate..." << endl;

    bool hasX = any_of(
        this->inputs.begin(),
        this->inputs.end(),
        [] (Wire* x) {
            return x->getVal() == Logic::X;
        }
    );

    bool allZ = all_of(
        this->inputs.begin(),
        this->inputs.end(),
        [] (Wire* x) {
            return x->getVal() == Logic::Z;
        }
    );
    
    bool all1 = all_of(
        this->inputs.begin(),
        this->inputs.end(),
        [] (Wire* x) {
            return x->getVal() == Logic::ONE;
        }
    );

    this->output->setVal(!all1);

    return hasX ?
        Logic::X :
        (allZ ? Logic::Z :(all1 ? Logic::ZERO : Logic::ONE));
}
