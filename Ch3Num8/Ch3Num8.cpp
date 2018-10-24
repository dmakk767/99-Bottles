// Ch3Num8.cpp : Defines the entry point for the console application.
//

//99 bottles of beer on the wall

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> split_into_digits(vector<int> digits, int value);


int main()
{
	string tenthPlace[11] = {" ", "Ten ","Twenty ","Thirty ","Fourty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety ","One-Hundred "};
	string onesPlace[11] = { "Zero ", "One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ", "Ten " };
	string teens[10] = { "Ten ", "Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen " };
	string song1 = "bottles of beer on the wall, ";
	string song2 = "bottles of beer\, Take one down\, pass it around\, ";
	vector<int> digits;

	for (int counter= 100; counter >= 0; counter--)
	{
		vector<int> digits = split_into_digits(digits, counter);
	//	cout << counter << endl;
//		cout << digits[0] << " , " << digits[1] << endl;
	if (counter == 100)
		{
			cout << tenthPlace[10] << song1 << endl;
			cout << tenthPlace[10] << song2 << endl;
		}
	else if ((counter % 10 == 0) && (counter != 0))
	{
		cout << tenthPlace[digits[0]] << song1 << endl;
		cout << tenthPlace[digits[0]] << song2 << endl;

	}
	else if ((counter < 20) && (counter > 10))
	{
		cout << teens[digits[1]] << song1 << endl;
		cout << teens[digits[1]] << song2 << endl;
	}

	else if ((counter <11) && (counter > 0))
	{
		cout << onesPlace[counter] << song1 << endl;
		cout << onesPlace[counter] << song2 << endl;
	}
	else if (counter == 0)
	{
		 cout << onesPlace[0] << song1 << endl;
		 
	}
	else
	{
		cout << tenthPlace[digits[0]] << onesPlace[digits[1]] << song1 << endl;
		cout << tenthPlace[digits[0]] << onesPlace[digits[1]] << song2 << endl;
	}
	
	}   
    return 0;
}

vector<int> split_into_digits(vector<int> digits, int value)
{
	
	for (; value > 0; value /= 10) digits.push_back(value % 10);
	reverse(digits.begin(), digits.end());
	return digits;
}