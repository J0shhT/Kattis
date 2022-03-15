#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int g;
		std::cin >> g;
		std::vector<int> codes;
		codes.reserve(g);
		for (; g > 0; --g)
		{
			int c;
			std::cin >> c;
			codes.push_back(c);
		}
		std::sort(codes.begin(), codes.end());
		for (auto iter = codes.cbegin(); iter != codes.cend(); iter += 2)
		{

			if (iter+1 == codes.cend() || *(iter+1) != *iter)
			{
				std::cout << "Case #" << std::to_string(i) << ": " << std::to_string(*iter) << std::endl;
				break;
			}
		}
	}
}