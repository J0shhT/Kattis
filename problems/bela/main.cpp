#include <iostream>
#include <string>
#include <limits>
#include <unordered_map>
#include <utility>

static std::unordered_map<char, std::pair<int, int>> values = {
	{'A', {11, 11}}, {'K', {4, 4}}, {'Q', {3, 3}}, {'J', {20, 2}},
	{'T', {10, 10}}, {'9', {14, 0}}, {'8', {0, 0}}, {'7', {0, 0}},
};

int main()
{
	int N;
	char B;
	int points = 0;

	std::cin >> N >> B;
	N *= 4;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (N-- > 0)
	{
		std::string line;
		std::getline(std::cin, line);
		const std::pair<int, int> &value = values[line.at(0)];
		if (line.at(1) == B)
			points += value.first;
		else
			points += value.second;
	}

	std::cout << points << std::endl;
	return 0;
}