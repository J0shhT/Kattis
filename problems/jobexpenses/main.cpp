#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	int sum = 0;
	while (N-- > 0)
	{
		int k = 0;
		std::cin >> k;
		if (k < 0) sum += -k;
	}
	std::cout << sum << std::endl;
	return 0;
}