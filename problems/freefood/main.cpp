#include <iostream>
#include <unordered_set>

int main()
{
	int N;
	std::cin >> N;

	std::unordered_set<int> days;
	days.reserve(365);
	while (N-- > 0)
	{
		int s, t;
		std::cin >> s >> t;
		for (int i = s; i <= t; ++i)
			days.insert(i);
	}
	std::cout << days.size() << '\n';
}