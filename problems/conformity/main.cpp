#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
	std::map<std::string, int> combinations;
	int mostPopular = 0;

	int n;
	std::cin >> n;

	std::vector<std::string> numbers;
	numbers.reserve(5);
	while (n--)
	{
		numbers.clear();
		std::string number;
		for (int i = 0; i < 5; ++i)
		{
			std::cin >> number;
			numbers.push_back(number);
		}
		std::sort(numbers.begin(), numbers.end());

		std::string combination;
		combination.reserve(numbers.size());
		for (const auto& str : numbers)
			combination += str;

		combinations[combination] += 1;
		int popularity = combinations[combination];
		if (popularity > mostPopular)
			mostPopular = popularity;
	}

	int count = 0;
	for (const auto& kvp : combinations)
		if (kvp.second == mostPopular)
			count += mostPopular;

	std::cout << count << std::endl;
}