#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int M;
	std::cin >> M;

	int T;
	int sum = 0;
	for (auto i = 0; i < M; ++i)
	{
		std::cin >> T;
		sum += T;
	}
	std::cout << sum / M << std::endl;
}