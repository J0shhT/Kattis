#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int sum = 0;
	while (n-- > 0)
	{
		int length;
		std::cin >> length;
		if (sum == 0)
		{
			sum += length;
		}
		else
		{
			sum += length - 1;
		}
	}
	std::cout << sum << std::endl;
}