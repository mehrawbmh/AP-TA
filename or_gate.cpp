#include "or_gate.hpp"

Logic OrGate::resolve()
{
   cout << "resolving or gate.. " << endl;

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
    
    bool has1 = any_of(
        this->inputs.begin(),
        this->inputs.end(),
        [] (Wire* x) {
            return x->getVal() == Logic::ONE;
        }
    );

    this->output->setVal(has1);

    return hasX ?
        Logic::X :
        (allZ ? Logic::Z :(has1 ? Logic::ONE : Logic::ZERO));
}

Logic NorGate::resolve()
{
    cout << "resolving nor gate.. " << endl;

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
