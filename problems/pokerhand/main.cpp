#include <iostream>
#include <cstdio>
#include <unordered_map>


int main()
{
	char cards[5][3];
	scanf("%2s %2s %2s %2s %2s", cards[0], cards[1], cards[2], cards[3], cards[4]);

	std::unordered_map<char, size_t> counts;
	for (size_t i = 0; i < 5; ++i)
	{
		if (counts.find(cards[i][0]) != counts.end())
			++counts[cards[i][0]];
		else
			counts[cards[i][0]] = 1;
	}
	
	size_t max = 0;
	for (auto elem : counts)
	{
		if (elem.second > max)
			max = elem.second;
	}

	std::cout << max << std::endl;
	return 0;
}