#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> parseDigits(const std::string& str)
{
	std::vector<int> digits;
	std::stringstream input(str);
	int n = str.length() - (str.length() / 2);
	digits.reserve(n);
	while (n--)
	{
		int digit;
		input >> digit;
		digits.push_back(digit);
	}
	return digits;
}

void padFront(std::vector<int>& vec, int n)
{
	vec.reserve(n);
	while (n != vec.size())
		vec.insert(vec.cbegin(), 0);
}

int main()
{
	int t;
	std::cin >> t;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (t--)
	{
		std::string line1, line2;
		std::getline(std::cin, line1);
		std::getline(std::cin, line2);
		auto digits1 = parseDigits(line1);
		auto digits2 = parseDigits(line2);

		int size = std::max<int>(digits1.size(), digits2.size());
		padFront(digits1, size);
		padFront(digits2, size);

		int sum = 0;
		for (int i = 0; i < size; ++i)
			sum += (digits1[i] + digits2[i]) * (int)std::round(std::pow(10, size - i - 1));

		std::string sumStr = std::to_string(sum);
		for (int i = 0; i < sumStr.length(); ++i)
		{
			std::cout << sumStr[i];
			if (i != sumStr.length() - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
}