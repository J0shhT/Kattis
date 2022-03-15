#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	unsigned int jack, jill;
	
	while (std::cin >> jack >> jill && jack != 0 && jill != 0)
	{
		std::vector<unsigned int> jackCDs;
		jackCDs.reserve(jack);

		for (; jack > 0; --jack)
		{
			unsigned int cd;
			std::cin >> cd;
			jackCDs.push_back(cd);
		}

		int sold = 0;
		for (; jill > 0; --jill)
		{
			unsigned int cd;
			std::cin >> cd;
			if (std::binary_search(jackCDs.begin(), jackCDs.end(), cd))
			{
				sold++;
			}
		}

		std::cout << sold << "\n";
	}
}