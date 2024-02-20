#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;

	int a = 0, b = 0, c = 0;
	char ch;
	while (n-- > 0)
	{
		std::cin >> ch;
		if (ch == 'J')
			++a;
		std::cin >> ch;
		if (ch == 'J')
			++b;
		std::cin >> ch;
		if (ch == 'J')
			++c;
	}
	std::cout << std::min<int>(a, std::min<int>(b, c)) << std::endl;
}