#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	while (n != -1)
	{
		int milesDriven = 0;
		int last = 0;
		for (int i = 0; i < n; i++)
		{
			int mph, t;
			std::cin >> mph >> t;
			milesDriven += mph * abs(last - t);
			last = t;
		}
		std::cout << milesDriven << " miles\n";
		std::cin >> n;
	}
}