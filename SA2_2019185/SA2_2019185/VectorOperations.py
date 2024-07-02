from m5.params import *
from m5.SimObject import SimObject

class VectorOperations(SimObject):
    type = 'VectorOperations'
    cxx_header = "learning_gem5/part2/vector_operations.hh"
    cxx_class='gem5::VectorOperations'
    
    #time_to_wait = Param.Latency("Time before firing the event")
