#include <iomanip>
#include <iostream>

static const int diceCounts[] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;
	int sum = 0;
	int A;
	while (N-- > 0)
	{
		std::cin >> A;
		sum += diceCounts[A - 2];
	}
	std::cout << std::setprecision(15);
	std::cout << ((double)sum / 36.0) << std::endl;
}