#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	int t;
	std::cin >> t;
	while (t-- > 0)
	{
		int n;
		std::cin >> n;

		std::vector<int> positions;
		positions.reserve(n);

		while (n-- > 0)
		{
			int pos;
			std::cin >> pos;
			positions.push_back(pos);
		}

		std::sort(positions.begin(), positions.end());
		int min = positions.front();
		int max = positions.back();
		std::cout << (max - min) * 2 << '\n';
	}
}