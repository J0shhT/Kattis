#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	while (N--)
	{
		int b;
		double p;
		std::cin >> b >> p;

		double min, bpm, max;
		bpm = static_cast<double>(60*b)/p;
		min = bpm - (60/p);
		max = bpm + (60/p);
		std::cout << std::fixed;
		std::cout.precision(4);
		std::cout << min << ' ' << bpm << ' ' << max << std::endl;
	}
	return 0;
}