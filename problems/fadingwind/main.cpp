#include <cmath>
#include <iostream>

int main()
{
	int h, k, v, s;
	std::cin >> h >> k >> v >> s;
	int d = 0;
	while (h > 0)
	{
		// step 1
		v += s;
		v -= std::max<int>(1, int((double)v / 10.0));

		// step 2
		if (v >= k)
			h += 1;

		// step 3
		if (v > 0 && v < k)
		{
			h -= 1;
			if (h == 0)
				v = 0;
		}

		// step 4
		if (v <= 0)
		{
			h = 0;
			v = 0;
		}

		// step 5
		if (s > 0)
			s -= 1;

		d += v;
	}

	std::cout << d << std::endl;
}