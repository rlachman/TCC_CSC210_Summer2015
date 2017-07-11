#include <string>

using namespace std;

class romanType
{
	public:
		romanType();
		romanType(string st);
		romanType(const romanType & rhs);
		~romanType();
		
		int makeDecimal() const;
		int getDecimal() const;
		string getRoman() const;
		void setRoman(string s);
		void printroman() const;
		
	private:
		string myRoman;
		int myDecimal;
};
