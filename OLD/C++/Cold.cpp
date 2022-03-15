#include <iostream>

int main()
{
	int days;
	std::cin >> days;
	int underZero = 0;
	for (; days > 0; --days)
	{
		int temp;
		std::cin >> temp;
		if (temp < 0)
		{
			underZero++;
		}
	}
	std::cout << underZero;
}