#include <iostream>

int main()
{
	int i = 1;
	int n;
	while (std::cin >> n)
	{
		bool init = false;
		int value;
		int min, max, range;
		std::cin >> value;
		min = value;
		max = value;
		while (--n > 0)
		{
			std::cin >> value;
			if (value < min)
				min = value;
			if (value > max)
				max = value;
		}
		range = max - min;
		std::cout << "Case " << i << ": " << min << " " << max << " " << range << std::endl;
		++i;
	}
}