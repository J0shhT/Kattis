#include <iostream>

// #define DEBUG_TESTING
#define TEST_GROUP1
#define TEST_GROUP2
#define TEST_GROUP3

#ifdef DEBUG_TESTING
#include <cstdlib>
#include <ctime>
#endif

int main()
{
#ifdef DEBUG_TESTING
	std::srand(std::time(nullptr));
	int wins = 0;
	int loses = 0;
	for (int i = 0; i < 10000000; ++i)
#endif
	{
		int x = 0;
		while (x != 99)
		{
			if ((x + 1) % 3 == 0)
				x += 1;
			else if ((x + 2) % 3 == 0)
				x += 2;
			else
				x += (std::rand() % 2 == 0) ? 1 : 2;

#ifdef DEBUG_TESTING
				// std::cout << "> ";
#endif
#ifndef DEBUG_TESTING
			std::cout << x << std::endl;
#endif
			if (x == 99)
			{
#ifdef DEBUG_TESTING
				// std::cout << "Win" << std::endl;
				++wins;
#endif
				break;
			}

#ifdef DEBUG_TESTING

#if defined(TEST_GROUP1)
			x += 1;
#elif defined(TEST_GROUP2)
			x += 2;
#elif defined(TEST_GROUP3)
			if (std::rand() % 2 == 0)
				x += 1;
			else
				x += 2;
#endif
			// std::cout << x << std::endl;
			if (x == 99)
			{
				// std::cout << "Lost" << std::endl;
				++loses;
			}
#else
			std::cin >> x;
#endif
		}
	}

#ifdef DEBUG_TESTING
	std::cout << "Wins: " << wins << std::endl << "Loses: " << loses << std::endl;
#endif
}