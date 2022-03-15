#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

int main()
{
	std::string line;
	while (!std::cin.eof())
	{
		std::getline(std::cin, line);
		std::istringstream input(line);
		std::vector<int> integers{
			std::istream_iterator<int>(input),
			std::istream_iterator<int>()
		};
		for (auto iter1 = integers.cbegin(); iter1 != integers.cend(); ++iter1)
		{
			int target = *iter1;
			int sum = 0;
			for (auto iter2 = integers.cbegin(); iter2 != integers.cend(); ++iter2)
			{
				if (iter1 == iter2) continue;
				sum += *iter2;
			}
			if (target == sum)
			{
				std::cout << target << '\n';
				break;
			}
		}
	}
	return 0;
}