#include <iostream>
#include <string>
#include <climits>

int main()
{
	static auto conv = [](char c) -> int {
		switch (c)
		{
			case 'T': return 0;
			case 'C': return 1;
			case 'G': return 2;
			default:  return -1;
		}
	};

	std::string input;
	std::getline(std::cin, input);
	int counts[3] = { 0 };
	for (char c : input)
	{
		++counts[conv(c)];
	}
	int lowest = INT_MAX;
	for (size_t i = 0; i < 3; ++i)
	{
		if (counts[i] < lowest)
			lowest = counts[i];
	}
	std::cout << (counts[0]*counts[0] + counts[1]*counts[1] + counts[2]*counts[2] + (lowest*7)) << std::endl;
	return 0;
}