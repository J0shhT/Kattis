#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
	std::unordered_set<std::string> set;

	int N;
	std::cin >> N;
	while (N-- > 0 && set.size() < 12)
	{
		std::string uni, team;
		std::cin >> uni >> team;
		if (set.find(uni) == set.cend())
		{
			set.insert(uni);
			std::cout << uni << ' ' << team << '\n';
		}
	}
}