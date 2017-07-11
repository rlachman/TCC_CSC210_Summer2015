//circleType.h
#ifndef H_circleType   
#define H_circleType   

#include <fstream> 

using namespace std;

class circleType
{
public:
    void setRadius(double r);
      
      // Mutator ("setter")
      
      //Function to set the radius.
      //Postcondition: if (r >= 0) radius = r;
      //               otherwise radius = 0;

    double getRadius();
      
      // Accessor ("getter")
      
      //Function to return the radius.
      //Postcondition: The value of radius is returned.

    double area();
      //Function to return the area of a circle.
      //Postcondition: Area is calculated and returned.

    double circumference();
      //Function to return the circumference of a circle.
      //Postcondition: Circumference is calculated and returned.
      
    void print(ostream& outF);
      // function to print the radius, area, and circumference

    circleType(double r);
      //Constructor with one parameter.
      //Radius is set according to the parameter.
      //Postcondition: radius = r;
      //nice substitute instead of the circleType() default below

    circleType();
	  //The default value of the radius is 1.0;
      //Postcondition: radius = 1;
	
private:
    double radius;
};
#endif
