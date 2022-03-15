#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	while (n-- > 0)
	{
		int g;
		std::cin >> g;
		int last = -1;
		bool found = false;
		for (int i = 1; i <= g; ++i)
		{
			int value;
			std::cin >> value;
			if (found) continue;
			if (last >= 0 && (value - 1) != last)
			{
				std::cout << i << std::endl;
				found = true;
			}
			last = value;
		}
	}
}