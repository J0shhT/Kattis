#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	int* list = new int[N];
	for (int i = 0; i < N; ++i)
	{
		int n;
		std::cin >> n;
		list[i] = n;
	}
	for (int i = N - 1; i >= 0; --i)
		std::cout << list[i] << '\n';
}