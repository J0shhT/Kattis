#include <iostream>

int main()
{
	int value;
	std::cin >> value;
	int result = 0;
	while (value)
	{
		result <<= 1;
		result |= value & 1;
		value >>= 1;
	}
	std::cout << result;
}