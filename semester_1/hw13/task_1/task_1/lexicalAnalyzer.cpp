#include "lexicalAnalyzer.h"
#include <iostream>
#include <string>

using namespace std;

bool isDigit(const char &symbol)
{
	return (symbol >= '0' && symbol <= '9');
}

bool isDot(const char &symbol)
{
	return (symbol == '.');
}

bool isSign(const char &symbol)
{
	return (symbol == '+' || symbol == '-');
}

bool isExponent(const char &symbol)
{
	return (symbol == 'E');
}

bool isRealNumber(const string &str)
{
	const int sizeOfStr = str.length();
	int state = 0;
	char symbol = '0';

	for (int i = 0; i < sizeOfStr; ++i)
	{
		symbol = str[i];
		switch (state)
		{
		case 0:
		{
			if (isDigit(symbol))
			{
				state = 1;
			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if (isDigit(symbol))
			{
				state = 1;
			}
			else if (isDot(symbol))
			{
				state = 2;
			}
			else if (isExponent(symbol))
			{
				state = 4;
			}
			else
			{
				return false;
			}
			break;
		}
		case 2:
		{
			if (isDigit(symbol))
			{
				state = 3;
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if (isDigit(symbol))
			{
				state = 3;
			}
			else if (isExponent(symbol))
			{
				state = 4;
			}
			else
			{
				return false;
			}
			break;
		}
		case 4:
		{
			if (isSign(symbol))
			{
				state = 5;
			}
			else if (isDigit(symbol))
			{
				state = 6;
			}
			else
			{
				return false;
			}
			break;
		}
		case 5:
		{
			if (isDigit(symbol))
			{
				state = 6;
			}
			else
			{
				return false;
			}
			break;
		}
		case 6:
		{
			if (isDigit(symbol))
			{
				state = 6;
			}
			else
			{
				return false;
			}
			break;
		}
		}
	}
	return (state == 1 || state == 3 || state == 6);
}