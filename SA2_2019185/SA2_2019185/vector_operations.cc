#include "learning_gem5/part2/vector_operations.hh"
#include <vector>
#include <iostream>
#include "base/trace.hh"
#include "debug/VECTOR.hh"
#include "debug/ADDRESULT.hh"
#include "debug/DOTRESULT.hh"
#include "debug/NORMALIZE.hh"
#include <cmath>

namespace gem5
{
//int vec1[4] = {10,20,30,40};
//int vec2[4] = {4,5,6,7};
int vec1[4];
int vec2[4];


VectorOperations::VectorOperations(const VectorOperationsParams &params) :
    SimObject(params), event1([this]{VectorAddition();},name()), event2([this]{VectorDotProduct();},name()), event3([this]{NormalizeVector();},name())
{
    int lenOfArr3 = sizeof(vec1)/sizeof(vec1[0]);
    
    printf("Size of both vector is 4x1");
    printf("Enter the values for vector1 (4x1): ");
    for(int i = 0; i < lenOfArr3; i++){      
	scanf("%d", &vec1[i]);
    }

    printf("Enter the values for vector2 (4x1): ");
    for(int i = 0; i < lenOfArr3; i++){      
        scanf("%d", &vec2[i]);
    }

    //std::cout << "Hello World! From a SimObject!" << std::endl;
    DPRINTFR(VECTOR, "Created a VectorOperations Object\n");
    DPRINTF(VECTOR, "Vector 1 Output = [ %d, %d, %d, %d ]\n" , vec1[0], vec1[1], vec1[2], vec1[3]);
    DPRINTF(VECTOR, "Vector 2 Output = [ %d, %d, %d, %d ]\n" , vec2[0], vec2[1], vec2[2], vec2[3]);
    //DPRINTF(VECTOR, "%d , %d, %d, %d", vec1[0], vec1[1], vec1[2], vec1[3]);
}

void
VectorOperations::startup()
{
    int a;
    int b;
    int c;
    printf("Enter the latency value(ticks) for Vector addition event: ");
    scanf("%d", &a);
    printf("Enter the latency value(ticks) for Vector dot product event: ");
    scanf("%d", &b);
    printf("Enter the latency value(ticks) for Vector normalization event: ");
    scanf("%d", &c);
    
    //for(int i = 0; i < n1; i++)      
    //   scanf("%d", &a[i]);
    schedule(event1, a);
    schedule(event2, b);
    schedule(event3, c);
}

void 
VectorOperations::VectorAddition()
{
      
    //int vec1[] = {10,20,30,40};
    //int vec2[] = {4,5,6,7};
    int addvec[4]; 
    
    int lenOfArr3 = sizeof(vec1)/sizeof(vec1[0]);
    //printf("The merged array: ");
    for(int i=0; i<lenOfArr3; i++){
    	addvec[i] = vec1[i] + vec2[i];   
    }
    
    //for(int i=0; i<lenOfArr3; i++)
      //  printf(" %d ",addvec[i]);
   
    DPRINTF(ADDRESULT, "Resultant Vector after Vector Addition = [ %d, %d, %d, %d ]\n", addvec[0], addvec[1], addvec[2], addvec[3]);
     
} 

void 
VectorOperations::VectorDotProduct()
{
    //int vec1[] = {10,20,30,40};
    //int vec2[] = {4,5,6,7};
    int dotproduct = 0; 
    
    int lenOfArr3 = sizeof(vec1)/sizeof(vec1[0]);
    
    for(int i=0; i<lenOfArr3; i++){
    	dotproduct = dotproduct + vec1[i]*vec2[i];   
    }

    
    //printf(" %d ",dotproduct);
   
    DPRINTF(DOTRESULT, "Resultant Vector after Vector Dot Product = %d \n", dotproduct);
     
} 

void 
VectorOperations::NormalizeVector()
{
      
    //float vec1[] = {10,20,30,40};
    //float vec2[] = {4,5,6,7};
    float vec3[4];
    float vec4[4];
    float normaliseval1 = 0; 
    float normaliseval2 = 0;
    
    int lenOfArr3 = sizeof(vec1)/sizeof(vec1[0]);
    
    //printf("The merged array: ");
    
    for(int i=0; i<lenOfArr3; i++){
    	normaliseval1 = normaliseval1 + vec1[i]*vec1[i];   
    }
    
    for(int i=0; i<lenOfArr3; i++){
    	normaliseval2 = normaliseval2 + vec2[i]*vec2[i]; 
    }
    
    normaliseval1 = sqrt(normaliseval1);
    normaliseval2 = sqrt(normaliseval2);
    
    for(int i=0; i<lenOfArr3; i++){
    	vec3[i] = vec1[i]/normaliseval1;
    	vec4[i] = vec2[i]/normaliseval2;
    }
    
    //printf(" %d ",normaliseval1);
   
    DPRINTF(NORMALIZE, "Resultant Normalised Vector 1 = [ %f, %f, %f, %f ] \n", vec3[0], vec3[1], vec3[2], vec3[3]);
    DPRINTF(NORMALIZE, "Resultant Normalised Vector 2 = [ %f, %f, %f, %f ] \n", vec4[0], vec4[1], vec4[2], vec4[3]);
     
}
} // namespace gem5
