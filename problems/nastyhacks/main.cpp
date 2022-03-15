#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	while (n-- > 0)
	{
		int r, e, c;
		std::cin >> r >> e >> c;
		int ec = e-c;
		if (ec > r)
		{
			std::cout << "advertise";
		}
		else if (ec == r)
		{
			std::cout << "does not matter";
		}
		else
		{
			std::cout << "do not advertise";
		}
		std::cout << std::endl;
	}
}