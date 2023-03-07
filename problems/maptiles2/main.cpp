#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

static std::unordered_map<char, std::pair<int, int>> origins = {
	{'0', {0, 0}},
	{'1', {1, 0}},
	{'2', {0, 1}},
	{'3', {1, 1}},
};

int main()
{
	std::string key;
	std::cin >> key;
	std::pair<int, int> point = {0, 0};
	int level = key.length();
	for (char c : key)
	{
		int k = (int)(std::pow(2, level--) / 2.0);
		point.first += origins[c].first * k;
		point.second += origins[c].second * k;
	}
	std::cout << key.length() << ' ' << point.first << ' ' << point.second << std::endl;
}