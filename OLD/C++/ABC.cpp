#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	int x, y, z;
	std::cin >> x >> y >> z;

	std::vector<int> numbers = { x, y, z };
	std::sort(numbers.begin(), numbers.end(), [](int x, int y) -> bool {
		return x <= y;
	});

	std::string order;
	std::cin >> order;

	for (char c : order)
	{
		if (c == 'A')
		{
			std::cout << numbers[0] << " ";
		}
		else if (c == 'B')
		{
			std::cout << numbers[1] << " ";
		}
		else if (c == 'C')
		{
			std::cout << numbers[2] << " ";
		}
	}
}