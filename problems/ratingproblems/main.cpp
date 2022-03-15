#include <iostream>

int main()
{
	int n, k;
	std::cin >> n >> k;
	double min, max;
	double initial = 0;
	for (int i = 0; i < k; ++i)
	{
		int r;
		std::cin >> r;
		initial += r;
	}
	min = (initial + ((n-k)*-3.0))/n;
	max = (initial + ((n-k)*3.0))/n;
	std::cout << min << " " << max << std::endl;
}