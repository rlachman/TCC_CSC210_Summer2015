//Ryan Lachman and Harrison Hornsby
//CSC 210 - July 15 2015
//Project: Test various operations of a linked stack
 
#include <iostream>
#include <fstream>
#include <iomanip>
#include "linkedStack.h"
#include <sstream>//necessary to int to string conversion
  
using namespace std;

string hex(int);//passes in integer remainder over 9, returns alpha equivalent
void converter(linkedStackType<string> & stack);
void title();
void converter(linkedStackType<string> & stack);
void printStack(linkedStackType<string> & stack, int numType);
string getString(int iRemainder);

ifstream fin("input2.txt");//uses input file with errors to test exception handling
ofstream fout("output.txt");

int main() 
{
    title();
	
	linkedStackType<string> stack;//create new stack
	converter(stack);//calls converter function, reads in data, processes data, outputs data
    fout.close();
    
	system("pause");
	return 0;
}

void converter(linkedStackType<string> & stack)
{
	int deciOrig; int deciSave; int divisor; int quotient; int remainder; string st = ""; string sRemainder = "";
	int base[] = {16,8,2};
	string errmsg = "------------------------------Input Error--------------------------------\n";
	
		fin >> deciOrig;//Reads in number
		while(!fin.eof())
		{
			try{	
				if(!fin)//if input is not good
				{throw errmsg;}//skips to catch statement
				
				cout << setw(10) << right << deciOrig << "      " ;
				fout << setw(10) << right << deciOrig << "      " ;
				deciSave = deciOrig;//Saves copy of original decimal number input
	
				//convert deciSave to Hex
				//then print result
				do{
					divisor = base[0];//Sets base to 16
					quotient = deciSave / divisor; // assigns quotient
					remainder = deciSave % divisor; //saves remainder
					if(remainder <= 9)//If remainder is less than 9 then dont worry about alpha hex characters
					{ sRemainder = getString(remainder); //converts numeric remainder to string and saves to sRemainder
			    	stack.push(sRemainder);//pushes string remainder to stack
					}else if(remainder > 9)//if remainder is greater than 9
					{
					stack.push(hex(remainder));//converts remainder to alpha character, pushes alpha character to stack
					}
					deciSave = quotient;//saves quotient
				}while(quotient != 0);//while quotient is not 0, continue with loop
				printStack(stack,0);//Calls print stack function, prints top data, pops it, prints next until stack empty
			
				//then print result
				
				for(int i=1;i<3;i++)				//convert deciSave to Octal and then Binary using a for loop to traverse to octal and then binary column
				{
					divisor = base[i];//Sets base to 8
					deciSave = deciOrig;//sets copy of decimal back to orginal decimal number
					do{
						quotient = deciSave / divisor; // assigns quotient
						remainder = deciSave % divisor; //saves remainder
						sRemainder = getString(remainder); // converts to string
						stack.push(sRemainder);//pushes each remainder to stack
						deciSave = quotient;//saves quotient
					}while(quotient != 0);
					printStack(stack,i);//Calls print stack function, prints top data, pops it, prints next until stack empty
				}
	
				cout << endl;
				fout << endl;
				}// end of try
		
				catch(string msg)//if exception is thrown, control skips to here
				{
				cout << setw(77) << right << msg;
				fin.clear();
				fin.ignore(100,'\n');
				}// end of catch
			
			fin >> deciOrig;//last data read in
		
		}//end of outer while loop

}//end of converter function

void title()
{
	cout << setw(60) << right << "B  A  S  E    C  O  N  V  E  R  T  E  R" << endl
		 << setw(60)<< right  << "=======================================" << endl << endl
		 << setw(62) << right << "Written by Harrison Hornsby and Ryan Lachman" << endl << endl << endl;
	cout << setw(10) << right << "Decimal" << setw(18) << right <<"Hex" << setw(15) << right <<"Octal" << setw(33) << right <<"Binary" << endl <<
			setw(10) << right << "=======" << setw(18) << right <<"===" << setw(15) << right <<"=====" << setw(33) << right <<"======" << endl;
	
	fout << setw(60) << right << "B  A  S  E    C  O  N  V  E  R  T  E  R" << endl
		 << setw(60)<< right  << "=======================================" << endl << endl
		 << setw(62) << right << "Written by Harrison Hornsby and Ryan Lachman" << endl << endl << endl;
	fout << setw(10) << right << "Decimal" << setw(18) << right <<"Hex" << setw(15) << right <<"Octal" << setw(33) << right <<"Binary" << endl <<
			setw(10) << right << "=======" << setw(18) << right <<"===" << setw(15) << right <<"=====" << setw(33) << right <<"======" << endl;
}

void printStack(linkedStackType<string> & stack, int numType )//column will affect formatting, pass in column number
{
	int setWidth[] = {12,15,33};//array of ints, used for formatting inside of setw
	string typeResult[] = {" ", " ", " "};//array used to store result for concatenation
	
for(int j = 0;j<3;j++)
{
	if(numType==j)//0,1,2
	{
		while(!stack.isEmptyStack())
		{
		typeResult[j] = typeResult[j] + stack.top();//stores combined string into array
		stack.pop();
		}
	cout << setw(setWidth[j]) << right << typeResult[j];//prints combined string
	fout << setw(setWidth[j]) << right << typeResult[j];
	}
}//end of for loop
		
}//end of prinstack function

string getString(int iRemainder)
{
	string result;
	stringstream ss;

	
	for(int k=0;k<16;k++)//use for loop instead of switch
	{
		if(iRemainder==k)
		{
			ss << k;//sends int k to string stream for conversion
			result = ss.str(); //string stream function converts int to string and saves to result
		}
	}
		return result;

}

string hex(int copyRemainder)
{
	string result;
	string hexArray[] = {"A","B","C","D","E","F"};
	
	for(int k=10;k<16;k++)//use for loop instead of switch for converting integers to hex characters
	{
		if(copyRemainder==k)
		{
			result = hexArray[k-10];//matches up result with corresponding hex character from the hexArray
		}
	}
	
	return result; 
}
