#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
	long long fish;
	long long buyers;
	std::cin >> fish >> buyers;

	//weight
	std::vector<long long> fishWeights(fish);
	for (auto& i : fishWeights)
	{
		std::cin >> i;
	}

	//price, count
	std::vector<std::pair<long long, long long>> mongers(buyers);
	for (auto& iter : mongers)
	{
		std::cin >> iter.second >> iter.first;
	}

	std::sort(fishWeights.begin(), fishWeights.end());
	std::sort(mongers.begin(), mongers.end());
	
	long long profit = 0;
	while (fishWeights.size() > 0)
	{
		bool done = false;
		for (;;)
		{
			if (mongers.size() == 0)
			{
				done = true;
				break;
			}
			if (mongers.back().second == 0)
			{
				mongers.pop_back();
			}
			else break;
		}
		if (done) break;

		profit += fishWeights.back() * mongers.back().first;
		mongers.back().second--;
		fishWeights.pop_back();
	}

	std::cout << profit << std::endl;
	
	return 0;
}

