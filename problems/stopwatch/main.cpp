#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	if (n % 2 == 1)
	{
		std::cout << "still running" << std::endl;
	}
	else
	{
		int t = 0;
		int tlast = 0;
		bool on = false;
		while (n-- > 0)
		{
			int tnow;
			std::cin >> tnow;
			if (on)
				t += tnow - tlast;
			else
				tlast = tnow;
			on = !on;
		}
		std::cout << t << std::endl;
	}
}