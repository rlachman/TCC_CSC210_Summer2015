//circleType.cpp
//Imp file for the class circleType
#include <iostream>
#include <fstream>
#include <cmath> 

#include "circleType.h"

using namespace std;

void circleType::setRadius(double r)
{
    if (r >= 0)
        radius = r;
    else
        radius = 1;
}

double circleType::getRadius()
{
    return radius;
}

double circleType::area()
{
    return M_PI * radius * radius;// circle area formula
}

double circleType::circumference()
{
    return 2 * M_PI * radius;//circle circumference formula
}

void circleType::print(ostream& outF)
{
	outF << "Radius:  "      << radius          << "   " 
		 << "Area:    "      << area()          << "   "
		 << "Circumference " << circumference() << endl;  
}

circleType::circleType(double r)
{
    setRadius(r);
}

circleType::circleType()
{
	radius = 1;
}
