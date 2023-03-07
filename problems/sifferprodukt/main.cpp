#include <iostream>
#include <string>

int main()
{
	std::string input;
	input.reserve(4);
	std::cin >> input;
	while (input.length() > 1)
	{
		int result = 1;
		for (char c : input)
			if (c != '0')
				result *= (int)(c - '0');
		input = std::to_string(result);
	}
	std::cout << input;
}