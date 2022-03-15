#include <iostream>

int main()
{
	int X, Y, N;
	std::cin >> X >> Y >> N;
	for (int num = 1; num <= N; num++)
	{
		if (num % X != 0 && num % Y != 0)
		{
			std::cout << num;
		}
		if (num % X == 0)
		{
			std::cout << "Fizz";
		}
		if (num % Y == 0)
		{
			std::cout << "Buzz";
		}
		std::cout << "\n";
	}
}