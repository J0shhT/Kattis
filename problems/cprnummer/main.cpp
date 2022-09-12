#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::cin >> input;

	int sum = 0;
	static const int mul[] = {4, 3, 2, 7, 6, 5, 4, 3, 2, 1};
	for (int i, n = 0; i < input.length(); ++i)
	{
		char c = input[i];
		if (c == '-')
			continue;
		int val = int(c - '0');
		sum += val * mul[n++];
	}

	std::cout << (sum % 11 == 0) << std::endl;
}