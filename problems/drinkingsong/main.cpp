#include <iostream>
#include <string>

int main()
{
	int N;
	std::cin >> N;
	std::string word;
	std::cin >> word;
	for (int i = N; i > 0; --i)
	{
		std::cout << i << " bottle";
		if (i != 1)
			std::cout << 's';

		std::cout << " of " << word << " on the wall, ";

		std::cout << i << " bottle";
		if (i != 1)
			std::cout << 's';

		std::cout << " of " << word << ".\nTake ";

		int n = i - 1;
		if (n == 0)
			std::cout << "it";
		else
			std::cout << "one";

		std::cout << " down, pass it around, ";

		if (n == 0)
		{
			std::cout << "no more bottles of " << word << ".\n";
		}
		else
		{
			std::cout << n;

			std::cout << " bottle";
			if (n != 1)
				std::cout << 's';

			std::cout << " of " << word << " on the wall.\n";
		}

		if (i > 1)
			std::cout << '\n';

		/*
			3 bottles of " << word << " on the wall, 3 bottles of " << word << ".
			Take one down, pass it around, 2 bottles of " << word << " on the wall.
		*/
	}
}