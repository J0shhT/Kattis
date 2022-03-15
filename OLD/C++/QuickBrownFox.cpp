#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <locale>

int main()
{
	unsigned short numberOfLines = 0;
	std::cin >> numberOfLines;

	std::vector<std::string> lines = {};
	lines.reserve(numberOfLines);

	std::locale loc;

	std::cin.ignore(1000, '\n');
	for (int i = 0; i < numberOfLines; i++)
	{
		std::string line;
		std::getline(std::cin, line);
		lines.push_back(line);
	}

	for (std::string& line : lines)
	{
		std::map<char, bool> contains = {};
		for (char& c : line)
		{
			c = std::tolower(c, loc);
			if (c >= 97 && c <= 122)
			{
				contains[c] = true;
			}
		}
		if (contains.size() == 26)
		{
			std::cout << "pangram\n";
		}
		else
		{
			std::string missingCharacters;
			for (char c = 'a'; c <= 'z'; c++)
			{
				if (contains[c] != true)
				{
					missingCharacters += c;
				}
			}
			std::cout << "missing " << missingCharacters << "\n";
		}
	}
}