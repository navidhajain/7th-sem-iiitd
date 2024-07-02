#include "learning_gem5/part2/VectorOperation.hh"

#include <iostream>
#include<cmath>
#include "base/trace.hh"
#include "debug/VECTOR.hh"
#include "debug/ADDRESULT.hh"
#include "debug/DOTRESULT.hh"
#include "debug/NORMALIZE.hh"
namespace gem5
{

VectorOperation::VectorOperation(const VectorOperationParams &params) :
    SimObject(params),event([this]{VectorAddition();}, name()),event2([this]{VectorDotproduct();},name()),event3([this]{VectorNormalize();},name()),event4([this]{VectorUserInput();},name()),event5([this]{InputTicks();},name())
{
    
    //std::cout << "Hello World! From a SimObject!" << std::endl;
    //DPRINTF(VECTOR, "vector1 is %f %f %f %f\n",x[0],x[1],x[2],x[3]);
    //DPRINTF(VECTOR, "vector2 is.3 %f %f %f %f\n",y[0],y[1],y[2],y[3]);

}
double x[4];
double y[4];
int a1,a2,a3;
void
VectorOperation::startup(){
	//schedule(event5, 1);
	std::cout << "enter tick for addition \n";
	std::cin >> a1;
	std::cout << "enter tick for dotproduct \n";
	std::cin >> a2;
	std::cout << "enter tick for normalization \n";
	std::cin >> a3;
	
	schedule(event4, 10);
	//schedule(event, 100);
	//schedule(event2,1000);
	//schedule(event3,10000);
	schedule(event, a1);
	schedule(event2,a2);
	schedule(event3,a3);
}

void VectorOperation::InputTicks(){
	
	
}


void VectorOperation::VectorUserInput(){
	double n=4;
	//double x[4]={1,2,3,4};
	//double y[4]={5,6,7,8};
	std::cout << "enter inputs for vector1 ";
	for(int i=0;i<n;i++){
		int x1;
		std::cin >> x1;
		x[i]=x1;
	}
	std::cout << "enter inputs for vector2 ";
	for(int j=0;j<n;j++){
		int y1;
		std::cin >> y1;
		y[j]=y1;
	}
	
	
	DPRINTF(VECTOR, "vector1 is %f %f %f %f\n",x[0],x[1],x[2],x[3]);
    DPRINTF(VECTOR, "vector2 is %f %f %f %f\n",y[0],y[1],y[2],y[3]);	
}


void VectorOperation::VectorAddition(){
	double n=4;
	//double x[4]={1,2,3,4};
	//double y[4]={5,6,7,8};
	double addr[4];
	for(int i=0;i<n;i++){
		double a=x[i]+y[i];
		addr[i]=a;
		//DPRINTF("%d",a);
	}
	DPRINTF(ADDRESULT,"Vectors addition result= %f %f %f %f\n",addr[0],addr[1],addr[2],addr[3]);	
}

void VectorOperation::VectorDotproduct(){
	double n=4;
	//double x[4]={1,2,3,4};
	//double y[4]={5,6,7,8};
	//int dotr[n];
	double res=0;
	for(int i=0;i<n;i++){
		double a=x[i]*y[i];
		res=res+a;
		
	}	
	DPRINTF(DOTRESULT,"dot product result is %f\n",res);
}

void VectorOperation::VectorNormalize(){
	double n=4;
	//double x[4]={1,2,3,4};
	//double y[4]={5,6,7,8};
	double norr1[4];
	double norr2[4];
	double dx=0;
	double dy=0;
	//double res=0;
	for(int i=0;i<n;i++){
		double a1=x[i]*x[i];
		double a2=y[i]*y[i];
		dx=dx+a1;
		dy=dy+a2;
		//DPRINTF("%d",res);
	}
	dx=sqrt(dx);
	dy=sqrt(dy);
	for(int i=0;i<n;i++){
		norr1[i]=x[i]/dx;
		norr2[i]=y[i]/dy;
	}
	DPRINTF(NORMALIZE,"Vector1 normalize form= %f %f %f %f\n",norr1[0],norr1[1],norr1[2],norr1[3]);
	DPRINTF(NORMALIZE,"Vector2 normalize form= %f %f %f %f\n",norr2[0],norr2[1],norr2[2],norr2[3]);	
}

} // namespace gem5