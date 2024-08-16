#include "base_module.hpp"

void BaseModule::put(int id, const bool &val)
{
  auto wire = find_if(
      this->inputs.begin(),
      this->inputs.end(),
      [id](Wire *x) {
        return x->getId() == id; 
      }
  );

  if (wire == this->inputs.end())
  {
    throw NotFoundExcpetion("ID not found");
  }

  (*wire)->setVal(val);
}
