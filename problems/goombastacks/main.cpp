#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N;
	std::cin >> N;

	int g, b;
	int sum = 0;
	while (N-- > 0)
	{
		std::cin >> g >> b;
		sum += g;
		if (sum < b)
		{
			std::cout << "impossible" << std::endl;
			return 0;
		}
	}

	std::cout << "possible" << std::endl;
}