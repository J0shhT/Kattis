#include <iostream>
#include <iomanip>

int main()
{
	int n;
	std::cin >> n;
	double sum = 0;
	int count = 0;
	while (n-->0)
	{
		int i;
		std::cin >> i;
		if (i >= 0)
		{
			sum += i;
			++count;
		}
	}
	std::cout << std::setprecision(10) << sum/count << std::endl;
	return 0;
}