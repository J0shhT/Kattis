#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k, d;
	std::cin >> n >> k >> d;

	int x;
	int count = 0;
	int target = k + d - 14;
	while (n-- > 0)
	{
		std::cin >> x;
		if (x <= target)
			++count;
	}
	std::cout << count << std::endl;
}