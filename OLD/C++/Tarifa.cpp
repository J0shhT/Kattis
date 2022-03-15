#include <iostream>

int main()
{
	int x, n;
	std::cin >> x;
	std::cin >> n;

	int balance = x;
	for (int i = 0; i < n; i++)
	{
		int p;
		std::cin >> p;
		balance -= p;
		balance += x;
	}
	std::cout << balance;
	return 0;
}