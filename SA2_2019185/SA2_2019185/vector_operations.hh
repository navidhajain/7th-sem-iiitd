#ifndef __LEARNING_GEM5_VECTOR_OPERATIONS_HH__
#define __LEARNING_GEM5_VECTOR_OPERATIONS_HH__

#include "params/VectorOperations.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class VectorOperations: public SimObject
{
  private: 
  	
     void VectorAddition();
     EventFunctionWrapper event1;    

     void VectorDotProduct();
     EventFunctionWrapper event2;
     
     void NormalizeVector();
     EventFunctionWrapper event3;
     
  public:
     VectorOperations(const VectorOperationsParams &p);
     void startup();
    
};

} // namespace gem5

#endif // __LEARNING_GEM5_VECTOR_OPERATIONS_HH__
