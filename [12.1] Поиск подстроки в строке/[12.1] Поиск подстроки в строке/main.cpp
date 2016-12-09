#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"

struct SuffixTable
{
	char suffix;
	int value;
};

void loadFromFile(std::string &haystack)
{
	std::ifstream file("input.txt");
	if (file.is_open())
	{
		getline(file, haystack, '\0');
		file.close();
	}
	else
	{
		std::cout << "������ ��� �������� �����" << std::endl;
	}

}

bool isContained(const std::string &needle, char symbol)
{
	const int needleLength = needle.length();
	bool result = 0;
	for (int i = 0; i < needleLength; ++i)
	{
		if (needle[i] == symbol)
		{
			result = 1;
		}
	}
	return result;
}

void pushOrChange(Stack *stopSymbols, char symbol, int value)
{
	if (isContained(stopSymbols, symbol))
	{
		changeValue(stopSymbols, symbol, value);
	}
	else
	{
		push(stopSymbols, symbol, value);
	}
}

int prefixFunction(const std::string &needle)
{
	int prefixFunction = 0;
	const int needleLength = needle.length();

	for (int i = 0; i < needleLength / 2; ++i)
	{
		if (needle[i] == needle[needleLength - i + 1])
		{
			++prefixFunction;
		}
		break;
	}
	return prefixFunction;
}

void inputStopSymbols(Stack *stopSymbols, const std::string &needle, const std::string &haystack)
{
	const int haystackLength = haystack.length();

	for (int i = 0; i < haystackLength - 1; ++i)
	{
		if (isContained(needle, haystack[i]))
		{
			pushOrChange(stopSymbols, haystack[i], i + 1);
		}
		else
		{
			pushOrChange(stopSymbols, haystack[i], 0);
		}
	}

	if (!isContained(needle, haystack[haystackLength - 1]))
	{
		push(stopSymbols, haystack[haystackLength - 1], 0);
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	short numberOfUniqueSymbols = 0;
	std::string haystack = "";
	std::string needle = "";
	Stack *stopSymbols = createStack();

	std::cout << "������� �������" << std::endl;
	getline(std::cin, needle);
	const int needleLength = needle.length();
	loadFromFile(haystack);
	inputStopSymbols(stopSymbols, needle, haystack);
	SuffixTable *suffixTable = new SuffixTable[needleLength + 1];

	delete suffixTable[];
	suffixTable = nullptr;
}