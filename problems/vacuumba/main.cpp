#include <iostream>
#include <iomanip>

#define _USE_MATH_DEFINES
#include <math.h>

struct Vec2D
{
	double x;
	double y;
};

int main()
{
	int n;
	std::cin >> n;
	while (n-->0)
	{
		double angle = M_PI_2;
		Vec2D pos = { .x = 0.0, .y = 0.0 };
		
		int m;
		std::cin >> m;
		while (m-->0)
		{
			double a, d;
			std::cin >> a >> d;
			a *= (M_PI / 180.0);
			angle += a;
			pos.x += d * cos(angle);
			pos.y += d * sin(angle);
		}

		printf("%.6f %.6f\n", pos.x, pos.y);
	}
	return 0;
}