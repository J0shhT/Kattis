#include <iostream>
#include <string>
#include <algorithm>

static char numToChar(unsigned int num)
{
	if (num >= 10)
		return 'A'+(num-10);
	return '0'+num;
}

static unsigned int charToNum(char c)
{
	if (c >= 'A')
		return 10+(c-'A');
	else
		return c-'0';
}

std::string decToBase(unsigned int num, unsigned int base)
{
	std::string numStr = "";
	double realNum = num;
	while (realNum > 0)
	{
		unsigned int value = num/base;
		unsigned int remainder = num%base;
		numStr += numToChar(remainder);
		realNum = num/base;
		num = value;
	}
	std::reverse(numStr.begin(), numStr.end());
	return numStr;
}

int main()
{
	int cases;
	std::cin >> cases;
	while (cases-- > 0)
	{
		int K, b;
		unsigned int n;
		std::cin >> K >> b >> n;
		std::string converted = decToBase(n, b);
		unsigned int result = 0;
		for (char c : converted)
		{
			unsigned int value = charToNum(c);
			result += value*value;
		}
		std::cout << K << ' ' << result << std::endl;
	}
}