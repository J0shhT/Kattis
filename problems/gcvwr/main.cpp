#include <iostream>

int main()
{
	int G, T, N;
	std::cin >> G >> T >> N;

	int W = 0;
	while (N-- > 0)
	{
		int w;
		std::cin >> w;
		W += w;
	}
	std::cout << 0.9 * (G - T) - W << '\n';
}