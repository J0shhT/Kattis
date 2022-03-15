#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> numbers;
	numbers.reserve(10);

	for (int i = 0; i < 10; i++)
	{
		int number;
		std::cin >> number;
		numbers.push_back(number % 42);
	}

	std::sort(numbers.begin(), numbers.end());
	numbers.resize(std::distance(numbers.begin(), std::unique(numbers.begin(), numbers.end())));

	std::cout << numbers.size();
}