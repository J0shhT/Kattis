#include <iostream>
#include <cmath>
#include <iomanip>

inline double calculate(double t, double a, double b, double x)
{
	return (t - (a * x)) / b;
}

bool isCloseTo(double a, double b)
{
	return abs(a - b) <= 0.000001;
}

bool isLessThanOrEqualTo(double a, double b)
{
	//std::cout << std::fixed << std::setprecision(30) << a << " " << b << "\n";
	if (!isCloseTo(a, b))
	{
		return a <= b;
	}
	else
	{
		return true;
	}
}

int main()
{
	double t, a, b;
	std::cin >> t;
	std::cin >> a;
	std::cin >> b;

	bool found = false;
	double x, y;
	double xIntercept = t / a;
	for (x = 0; isLessThanOrEqualTo(x, xIntercept); x++)
	{
		y = calculate(t, a, b, x);
		double diff_f = y - floor(y);
		double diff_c = y - ceil(y);
		//std::cout << std::fixed << std::setprecision(30) << x << " " << y << " " << diff_f << " " << diff_c << "\n";
		if (diff_c >= -0.000001 || diff_f <= 0.000001)
		{
			int ix = (x - ceil(x) >= -0.000001 ? ceil(x) : floor(x));
			int iy = (diff_c >= -0.000001 ? ceil(y) : floor(y));
			//if (ix != 0 || iy != 0)
			//{
				std::cout << ix << " " << iy << "\n";
				found = true;
			//}
		}
	}
	if (!found)
	{
		std::cout << "none\n";
	}
	//system("pause");
	return 0;
}