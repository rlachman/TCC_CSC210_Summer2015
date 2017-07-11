//cylinderType.cpp
//Imp File for the class cylinderType
#include <iostream>
#include <fstream>
#include <cmath> 

#include "cylinderType.h"

using namespace std;

void cylinderType::setHeight(double h)
{
 height = h;
}

double cylinderType::area()
{
    return 2.0 * M_PI * (getRadius() * getRadius()) + (circumference() * height); 
    // cylinder area formula
}

double cylinderType::volume()
{
    
	return M_PI * getRadius() * getRadius() * height;
    // cylinder volume formula
}

void cylinderType::print(ostream& outF)
{
	outF << setw(11) << getRadius()
		 << setw(10) << height 
		 << setw(9) << area()
		 << setw(10) << volume() << endl;
}

// constructor with 2 parameters
cylinderType::cylinderType(double r, double h)
					: circleType(r) //calls base constuctor
{
    height = h;
}
// default constructor
cylinderType::cylinderType()
					: circleType(1.0)//sets base constructor
{
	height = 1.0;
}
