#include <iostream>
#include <cstring>
#include "romanType.h"

romanType::romanType()
			:myRoman("M")
{
		myDecimal = 1000;
}



romanType::romanType(string st)		// Constructor
{
	myRoman = st;
	myDecimal = makeDecimal();
}

romanType::~romanType()				// Destructor
{
	cout << "I'm destroyed." << endl;
}


int romanType ::getDecimal() const
{
	return myDecimal;
}

void romanType::setRoman(string s)
{
	myRoman = s;
}

string romanType::getRoman() const
{
	return myRoman;
}

int romanType::makeDecimal() const
{
	int result = 0;
	int accum = 0;
	int lastResult = 1000000000;
	bool flag = false;			// flag variable to keep track of consective 'I' and 'IX'
	bool flag2 = false;			// Flag2 variable to keep track of negative numbers
	for(int i = 0; i < myRoman.length(); i++)
	{
		char ch = myRoman[i];
		 
		switch (ch)
	    {
			case 'T':
				accum = -1;
				flag2 = true;
				break;
	    	case 'M':				// For M value if 1000
	    		result = 1000;
	    		break;
	    	case 'D':				// For D value is 500
	    		result = 500;
	    		break;
			case 'C':				// For C value is 100
	    		result = 100;
	    		break;
			case 'L':				// For L value is 50
	    		result = 50;
	    		break;
			case 'X':				
				if(flag)
				{
					result = 9;			// If flag is true means we have 'I' already in the input. So result is IX = 9
					flag = false;
					break;
				}
				else
				{
					result = 10;		// Else result is 10
					break;
				}
	    		
			case 'V':
				if(flag)
				{
					result = 4;		// If flag is true we have 'I' in already in the input. So result is IV = 4
					flag = false;
				}
				else
				{
					result = 5;		// Else result is flag.
				}
	    		break;	
			case 'I':
				if(!flag)
				{
					result = 1;			// Since we have first I so make flag = TRUE
					flag = true;
					break;
				}
				else
				{
					result = result + 1;		// Else flag is true and keep on adding
					break;
				}
				
				
	    }
		
		if(i == myRoman.length()-1)
			flag = false;
		if(!flag)					// If flag is true we continue else we add to the accumulated result.
			accum = accum + result;
		
		if(flag2)				// For negative numbers
			accum = -1;
	}
	
	//cout << accum << endl;
	//myDecimal = accum;
	return accum;
}
// finish implament
