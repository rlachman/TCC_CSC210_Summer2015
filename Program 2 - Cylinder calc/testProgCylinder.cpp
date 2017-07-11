//Ryan Lachman 
//CSC 201 - June 15 2015
//Project: Cylinder Calculations

#include <iostream> 
#include <iomanip>
#include <fstream>

#include "circleType.cpp"
#include "cylinderType.cpp"

void title();

using namespace std;

ifstream fin;//setting up the input of text file
ofstream fout;//setting up output of text file

int main()
{   
    fin.open("cylinderIn.txt");//declaring name of text file to read in
	fout.open("cylinderOut.txt");//delcaring text file to create when reading out

    title();//calling title for heading

   	cout << setprecision(2) << fixed;// setting the 2 deciaml placement for cout
	fout << setprecision(2) << fixed;// setting the 2 decimal placemtn for text file (fout)

	double radius = 0;
	double height = 0;
	
    cylinderType dcyl;// makes object with no parameter (default)
	cylinderType cyl1(2.5,7.1);//reads constructor with the 2 parameters
	
    dcyl.print(cout);// prints the default values of the dcyl
    dcyl.print(fout);
    cyl1.print(cout);// prints the values from constructor with 2 parameters
    cyl1.print(fout);
	
	for(int i = 0; i <= 5; i++)// for loop to read 6 input values 
    {
    fin >> radius >> height;// reading the first and second numerical figures from the input text
	cylinderType cyl1(radius,height);
    cyl1.print(cout);// prints the results using the inputed values from text
	cyl1.print(fout);
    }
	
    system("pause");
	return 0;
}

void title()
{
    cout << setw(10) << " C Y L I N D E R    C A L C U L A T I O N S"   << endl << endl;
	cout << setw(10) << "               by Ryan Lachman"                << endl << endl << endl;
	cout << setw(11) << "Radius" << setw(10) << "Height" << setw(9) << "S.Area"  << setw(10) << "Volume" << endl;
	cout << setw(11) << "------" << setw(10) << "------" << setw(9) << "------"  << setw(10) << "------" << endl << endl;
	
	fout << setw(10) << " C Y L I N D E R    C A L C U L A T I O N S"   << endl << endl;
	fout << setw(10) << "               by Ryan Lachman"                << endl << endl << endl;
	fout << setw(11) << "Radius" << setw(10) << "Height" << setw(9) << "S.Area"  << setw(10) << "Volume" << endl;
	fout << setw(11) << "------" << setw(10) << "------" << setw(9) << "------"  << setw(10) << "------" << endl << endl;
}
