//Ryan Lachman 
//CSC 210 - June 3 2015
//Project: Roman Numeral Converter

#include <iostream>
#include <fstream>
#include <iomanip>
#include "romanType.cpp"

void title();

using namespace std;

ofstream fout  ("romanOuput.txt");

int main()
{
	const int SIZE = 4;
	string array [] = {"MCXIV", "CCCLIX", "MDCLXVI", "MMMCMLXXXITV"};		
                                      // String array containing roman numerals
	
	romanType rt;
	int decimal;
	title();			                     // Title function defined below
	
	for(int i = 0; i < SIZE; i++)
	{
		rt.setRoman(array[i]);				// RomanType constructor
		
		cout << setw(23) << rt.getRoman();
		int decimal = rt.makeDecimal();		// Make decimal and display decimal
		cout << setw(16) << decimal << endl;
		
		fout << setw(23) << rt.getRoman();	// Make decimal and display decimal
		fout << setw(16) << decimal << endl;
	}
	cout << endl << endl << endl << endl;
	fout << endl << endl << endl << endl;
	
	fout.close();
	system("pause");
	return 0;
}

void title()
{
	cout << "        R O M A N    N U M E A L   C O N V E R T E R" <<endl<<endl;
	cout << "                           by"					    << endl << endl;
	cout << "                      Ryan Lachman"				<< endl << endl;
	cout << setw(24) << "Numeral " <<  setw(15) << " Decimal"	<< endl << endl;
	
	fout << "        R O M A N    N U M E A L   C O N V E R T E R" <<endl<<endl;
	fout << "                           by"						<< endl << endl;
	fout << "                      Ryan Lachman"				<< endl << endl;
	fout << setw(24) << "Numeral " <<  setw(15) << " Decimal"	<< endl << endl;
}

