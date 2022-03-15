#include <iostream>

int main()
{
	int n, dummy;
	std::cin >> n;
	std::cin >> dummy >> dummy;
	--n;
	int tlast = 0;
	int dlast = 0;
	int max = 0;
	while (n-- > 0)
	{
		int t, d;
		std::cin >> t >> d;
		int v = (d-dlast)/(t-tlast);
		if (v > max)
			max = v;
		tlast = t;
		dlast = d;
	}
	std::cout << max << std::endl;
}