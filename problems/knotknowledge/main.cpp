#include <iostream>
#include <unordered_set>

int main()
{
	int N;
	std::cin >> N;
	std::unordered_set<int> set;
	for (int i = 0; i < N; ++i)
	{
		int x;
		std::cin >> x;
		set.insert(x);
	}
	for (int i = 0; i < N - 1; ++i)
	{
		int y;
		std::cin >> y;
		set.erase(y);
	}
	std::cout << *set.begin() << '\n';
}