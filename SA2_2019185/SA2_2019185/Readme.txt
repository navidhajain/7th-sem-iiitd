VectorOperations.py 
We have to define a SimObject named VectorOperations. Additionally, each SimObject has a corresponding Python class. It contains the information about the c++ class that is to be wrapped with this SimObject. We have created the VectorOperations.py in scr/learning_gem5/part2. There is a header file and the C++ class and type.
cxx_header which contains the declaration of class VectorOperation. The naming convention is followed which is all lowercase and underscores. Cxx_class will create the SimObject within the gem5 namespace. 


vector_operations.hh
We have created vector_operation.hh and vector_operayions.cc which will implement the SimObject VectorOperations. 
Gem5 customarily encapsulates all header files in #ifndef/#endif along with the file name and directory they are in.  We declare our class within the namespace gem5.  We have created a constructor for VectorOperations SimObject which will take parameter objects based on .py class. Name of this parameter is “VectorOperaions” and the type name is “VectorOperationsParams”. The class VectorOperations is inherited from SimObject publicly. We also included the constructor for VectorOperations in public scope. 

vector_operations.hh will contain all the declarations given in the question. It is given that VectorOperations will call three events which are “VectorAddition”, “VectorDotProduct” and “NormalizeVector”. Each of these events will have a callback function which inherits from :cppEvent. And Each of these events will be executed at specific ticks.And the startup function is used for scheduling the given events in the assignment. 

In the header file we will declare these three functions in private scope, we want to execute and The EventFunctionWrapper which is used to wrap the events which takes two parameters, a function to execute and a name. These functions take no input parameters and return no value as specified in assignment that these events will not store the resultant values in the code and rather it will compute each time when the events are called. 


vector_operations.cc
I have implemented all the functions in this .cc file. First function is the constructor for VectorOperations, in which we pass the parameter object of all the event names. Take two vectors which are vec1 and vec2 of size 4 x 1 each. 
We capture [this] in the lambda that calls member function of instance of the class. And we will call event1, event2 and event3 defined in the header file under EventFunction Wrapper. 

Scheduling events will be done in startup(). We will use :cppschedule function which will initially schedule using schedule(event, ticks)  we added to the VectorOperations class. As given VectorAddition event will take place at 100 ticks and VectorDotProduct event will be called at 1000 ticks and NormalizeVector event will be called at 10000 ticks. 

We will define the implementation of VectorAddition, VectorDotProduct and NormalizeVector. 
VectorAddition event will be done by taking global values of vec1 and vec2 and defining “addvec” of integer values with dimension of 4 x 1. Vector 1 and Vector 2 can take only integer values. Int lenofArr3 will give the length of the vector. A for loop is used which will run from 0 till the length of the vector. And it will take one value of vec1 and another value of vec2 and add both values and store in addvec. Addvec will give the final resultant vector after addition of vec1 and vec2. 

VectorDotProduct event will also take global values of vec1 and vec2 and value of dotproduct variable is initialized with 0 and then for loop is applied which take each value of vec1 and vec2 and store the value in dot product and add other values calculated from the loop in this. And after the loop overs, we will get one value in dotproduct. 

NormalizeVector will take two float variables normaliseval1 and normaliseval2 and initialize it to zero. lenofArr3 will give the length of the vector. The for loop will run from 0 till the length of the vector. And normaliseval1 will be equal to normaliseval1 sum with vec1[i]*vec1[i]. It will store summation of the square of each value present in vec1. Similarly for normaliseval2, will stor the summation of square of each value present in vec2. 
The for loop will run from 0 till the length of vector and vec3 will store the value of vec1 divided by the normalized val1. Similarly, vec4 will give the final results after dividing vec2 with normaliseval2. 

We create debug flags and declare them in the SConscript file. We also have to include the header file in .cc file with “debug/name_of_debug.hh”. We will write a debug statement with the format specified in the documentation. “VECTOR” debug flag will print the input vector. “ADDRESULT” debug flag will print the result of addition of 2 vectors stored in addvec with dimension 4 x 1. “DOTRESULT” will print the resultant value after dotproduct of vec1 and vec2. 
“NORMALIZE” will print the resultant value after normalizing the vector. 


BONUS :

1. Taking the latency value(cycles) to execute the 3 events from the user. 
 I declared  three variables a,b,c which will take integer values which we will be taking from the user using scanf function. And then put these variables in the startup() function and in the schedule(event1, latency) and send these values to the latency parameter. 
 
2. Input Vector elements from the user :
After declaring global vectors vec1 and vec2 of dimension 4 x 1. And the elements of vec1 and vec2 will be taken from the user as inputs using scanf and for loop. For loop will run from 0 till length of vector and each value of vec1 is taken from user and stored in vec1  


SConscript 
Registering the SimObject and C++ file.
In order to compile c++ and python files,  we need to tell the build system all the information about the new SimObject. We declare the SimObject and .cc file. Also we need to include the debugflags with names specified in the assignment here. 

run_simple.py 
This file is made in configs/learning_gem5/part2 to instantiate the object. 
After adding the flags, we will create the configuration script for our VectorOperation SimObject.
First we will import m5 and all objects we have compiled, then set up the  root Simobject, then root.VectorObj creates the instantiation of the VectorOperations simobject. Then call the instantiate on the m5 module and run the simulation. 
  
Compile and run the code : 
first write all the files then, git checkout command will run and after that rerun the build command which is scons build/X86/gem5.opt

To compile the code all the code will be stored in src/learning_gem5/part2 expect for the run_simple.py which configs/learning_gem5/part2. 

this command will be cmd with cd gem5/ 
build/X86/gem5.opt --debug-flags=VECTOR,ADDRESULT,DOTRESULT,NORMALIZE configs/learning_gem5/part2/run_simple.py
debug flags can be deleted if we want to run one by one. 

Output 
Size of both vector is 4x1Enter the values for vector1 (4x1): 10 20 30 40
Enter the values for vector2 (4x1): 50 60 70 80 
Created a VectorOperations Object
      0: vectorObj: Vector 1 Output = [ 10, 20, 30, 40 ]
      0: vectorObj: Vector 2 Output = [ 50, 60, 70, 80 ]
Beginning simulation!
Enter the latency value(ticks) for Vector addition event: 100
Enter the latency value(ticks) for Vector dot product event: 200 
Enter the latency value(ticks) for Vector normalization event: 3000
build/X86/sim/simulate.cc:194: info: Entering event queue @ 0.  Starting simulation...
    100: vectorObj: Resultant Vector after Vector Addition = [ 60, 80, 100, 120 ]
    200: vectorObj: Resultant Vector after Vector Dot Product = 7000 
   3000: vectorObj: Resultant Normalised Vector 1 = [ 0.182574, 0.365148, 0.547723, 0.730297 ] 
   3000: vectorObj: Resultant Normalised Vector 2 = [ 0.379049, 0.454859, 0.530669, 0.606478 ]