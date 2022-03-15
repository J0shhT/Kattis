#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main()
{
	int cases;
	std::cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		double v, angle, d, h1, h2;
		std::cin >> v >> angle >> d >> h1 >> h2;

		angle = angle * (M_PI / 180.0);
		double y = d * tan(angle) - 0.5 * 9.81 * pow(d / (v * cos(angle)), 2);

		if (y - h1 >= 1 && h2 - y >= 1)
		{
			std::cout << "Safe\n";
		}
		else
		{
			std::cout << "Not Safe\n";
		}
	}
}