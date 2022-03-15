#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

int main()
{
	std::string input;
	std::getline(std::cin, input);

	std::unordered_set<std::string> words;
	std::string word;
	for (char c : input)
	{
		if (c == ' ')
		{
			if (words.find(word) != words.cend())
			{
				std::cout << "no" << std::endl;
				return 0;
			}
			words.insert(word);
			word = "";
			continue;
		}
		word += c;
	}
	if (!word.empty() && words.find(word) != words.cend())
	{
		std::cout << "no" << std::endl;
		return 0;
	}
	std::cout << "yes" << std::endl;
}