#ifndef __LEARNING_GEM5_VectorOperation_HH__
#define __LEARNING_GEM5_VectorOperation_HH__

#include "params/VectorOperation.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class VectorOperation : public SimObject
{
  private:
    void VectorAddition();
    EventFunctionWrapper event;
    
    void VectorDotproduct();
    EventFunctionWrapper event2;
    
    void VectorNormalize();
    EventFunctionWrapper event3;
    
    void VectorUserInput();
    EventFunctionWrapper event4;
    
    void InputTicks();
    EventFunctionWrapper event5;
    
    
  public:
    VectorOperation(const VectorOperationParams &p);
    void startup();
};

} // namespace gem5

#endif // __LEARNING_GEM5_HELLO_OBJECT_HH__