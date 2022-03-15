#include <iostream>

int main()
{
	int T;
	std::cin >> T;
	while (T-- > 0)
	{
		int N;
		std::cin >> N;

		uint64_t rsum = 0;
		for (int i = 0; i < N; ++i)
		{
			uint64_t n;
			std::cin >> n;
			rsum += n % N;
		}
		rsum %= N;

		std::cout << (rsum == 0 ? "YES" : "NO") << '\n';
	}
}