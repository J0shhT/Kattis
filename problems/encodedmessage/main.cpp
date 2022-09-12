#include <cmath>
#include <iostream>
#include <string>

int main()
{
	int N;
	std::cin >> N;
	while (N-- > 0)
	{
		std::string input;
		std::cin >> input;
		size_t n = sqrt(input.length());
		for (int x = n - 1; x >= 0; --x)
			for (int y = 0; y < n; ++y)
				std::cout << input.at((y * n) + x);
		std::cout << '\n';
	}
}