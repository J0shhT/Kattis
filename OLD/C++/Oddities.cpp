#include <iostream>

int main()
{
	int i;
	std::cin >> i;
	for (; i > 0; --i)
	{
		int x;
		std::cin >> x;
		if (abs(x) % 2 == 0)
		{
			std::cout << x << " is even\n";
		}
		else
		{
			std::cout << x << " is odd\n";
		}
	}
}