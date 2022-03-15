#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str, char delim)
{
	std::vector<std::string> substrVec;
	std::string substr;
	for (const char c : str)
	{
		if (c == delim)
		{
			if (!substr.empty())
			{
				substrVec.push_back(substr);
				substr = "";
			}
			continue;
		}
		substr.push_back(c);
	}
	if (!substr.empty())
		substrVec.push_back(substr);
	return substrVec;
}

int main()
{
	std::string input;
	std::getline(std::cin, input);
	std::vector<std::string> problems = split(input, ';');
	size_t count = 0;
	for (std::string problem : problems)
	{
		size_t pos = problem.find('-');
		if (pos != std::string::npos)
		{
			std::string s1 = problem.substr(0, pos);
			std::string s2 = problem.substr(pos+1);
			int n1 = std::stoi(s1);
			int n2 = std::stoi(s2);
			count += n2 - n1 + 1;
		}
		else
		{
			++count;
		}
	}
	std::cout << count << std::endl;
	return 0;
}