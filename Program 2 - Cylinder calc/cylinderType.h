//cylinderType.h
#ifndef H_cylinderType   
#define H_cylinderType  

#include <fstream>     

using namespace std;

class cylinderType: public circleType
{
public:
    cylinderType(double r, double h);
    //Constructor with two parameter.
    //Radius is set according to the parameter.
    //Postcondition: radius = r;
    //Postcondition: height = h;
    //nice substitute instead of the circleType() default below
     
	cylinderType();
	//The default value of the radius is 1.0;
	//The default value of the radius is 1.0;
    //Postcondition: radius = 1; 

	void setHeight(double h);
    //Function to set the height.
    //Postcondition: height = h
    
	double getheight();
    //Function to return the height of the cylinder.
    //Postcondition: The value of radius is returned.

    double area();
    //Function to return the area of a circle.
    //Postcondition: Area is calculated and returned.
      
    double volume();
	//Function to retun the volume of the cylinder
	//Postcondition: Volume is calculted and returned
	  
    void print(ostream& outF);
    //Function to print the statistics of th cylinder

private:
    double height;
};
#endif
