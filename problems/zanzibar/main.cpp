#include <iostream>

int main()
{
	int T;
	std::cin >> T;
	while (T--)
	{
		int prev = 1;
		int count = 0;
		int num;
		while (std::cin >> num, num > 0)
		{
			if (num > prev*2)
				count += num - (prev*2);
			prev = num;
		}
		std::cout << count << std::endl;
	}
	return 0;
}