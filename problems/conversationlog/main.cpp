#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>

int main()
{
	int m;
	std::cin >> m;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::unordered_map<std::string, size_t> occurences;
	occurences.reserve(141421);

	std::unordered_map<std::string, std::set<std::string>> users;
	users.reserve(m);

	std::string input;
	std::stringstream words;
	while (m--)
	{
		std::getline(std::cin, input);

		words.clear();
		words.str(input);
		words >> input; // their name

		auto& usersWords = users[input];
		while (words.good())
		{
			words >> input;
			usersWords.emplace(input);
			++occurences[input];
		}
	}

	using entry = std::pair<std::string, size_t>;
	auto sortingFunc = [](const entry& a, const entry& b)
	{
		if (a.second > b.second)
			return true;
		else if (a.second == b.second)
			return a.first < b.first;
		else
			return false;
	};

	std::set<entry, decltype(sortingFunc)> sortedWords(occurences.cbegin(), occurences.cend(), sortingFunc);

	size_t count = 0;
	for (const auto& word : sortedWords)
	{
		bool skip = false;
		for (const auto& usersWords : users)
		{
			if (usersWords.second.count(word.first) == 0)
			{
				skip = true;
				break;
			}
		}

		if (skip)
			continue;

		++count;
		std::cout << word.first << '\n';
	}

	if (count == 0)
		std::cout << "ALL CLEAR\n";
}