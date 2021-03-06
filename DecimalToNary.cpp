#include "stdafx.h"
#include <iostream>
#define SIZE 100

using namespace std;

class DecimalToNary
{
	int decimal, base, remainderArray[SIZE];

	public: 

	void ReadData()
	{
		cout << "Enter a number in base 10 : ";
		cin >> decimal;

		cout << "\nEnter the base : ";
		cin >> base;

		if ((decimal < 0 || decimal > 255) && (base > 1 || base < 17))
		{
			cout << "Input should be a non-negative number from 0 to 256 inclusive and base should be of any order between 2 and 16.";
		}
	}

	void ConvertDecimalToNary()
	{
		int number = decimal, count = 0;
		if (base > decimal && base < 10)
		{
			cout << "Input in base " << base << "is : " << decimal << endl;
		}
		else
		{
			while (number >= base)
			{
				int remainder = number % base;
				remainderArray[count++] = remainder;
				int quotient = (number - remainder) / base;
				number = quotient;
				remainder = 0;
			}

			remainderArray[count++] = number;

			cout << "Input in base " << base << "is : ";
			for (int index = count - 1; index >= 0; index--)
			{
				switch (remainderArray[index])
				{
					case 10: cout << "A";
						break;
					case 11: cout << "B";
						break;
					case 12: cout << "C";
						break;
					case 13: cout << "D";
						break;
					case 14: cout << "E";
						break;
					case 15: cout << "F";
						break;

					default: cout << remainderArray[index];
				}
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	// Base 10 to Base 2 to 16
	DecimalToNary obj;

	try
	{
		obj.ReadData();
		obj.ConvertDecimalToNary();
	}
	catch (exception e)
	{
		throw e;
	}
	
	return 0;
}
