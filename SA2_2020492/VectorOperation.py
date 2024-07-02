from m5.params import *
from m5.SimObject import SimObject

class VectorOperation(SimObject):
    type = 'VectorOperation'
    cxx_header = "learning_gem5/part2/VectorOperation.hh"
    cxx_class = "gem5::VectorOperation"