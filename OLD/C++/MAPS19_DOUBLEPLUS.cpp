#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <unordered_set>

int main()
{
	std::string equation;
	std::cin >> equation;

	std::vector<int> numbers;

	std::string n = "";
	for (char c : equation)
	{
		if (c == '+')
		{
			numbers.push_back(std::stoi(n));
			n = "";
		}
		n += c;
	}
	if (n != "")
	{
		numbers.push_back(std::stoi(n));
		n = "";
	}

	std::unordered_set<int> possibleValues;
	for (auto iterEnd = numbers.end(); iterEnd != numbers.begin(); iterEnd--)
	{
		for (auto iterStart = numbers.begin(); iterStart != iterEnd; iterStart++)
		{
			std::string concatRight = "";
			std::string concatMid = "";
			std::string concatLeft = "";
			int sumRight = 0;
			int sumMid = 0;
			int sumLeft = 0;
			//right
			if (iterEnd != numbers.end())
			{
				for (auto iter = iterEnd; iter != numbers.end(); iter++)
				{
					concatRight += std::to_string(*iter);
					sumRight += *iter;
				}
			}
			//middle
			for (auto iter = iterStart; iter != iterEnd; iter++)
			{
				concatMid += std::to_string(*iter);
				sumMid += *iter;
			}
			//left
			if (numbers.begin() != iterStart)
			{
				for (auto iter = numbers.begin(); iter != iterStart; iter++)
				{
					concatLeft += std::to_string(*iter);
					sumLeft += *iter;
				}
			}

			possibleValues.emplace(std::stoi(concatLeft + concatMid + concatRight));
			possibleValues.emplace(std::stoi(concatLeft + concatMid) + sumRight);

			if (concatLeft != "")
				possibleValues.emplace(std::stoi(concatLeft) + sumMid + sumRight);
			else
				possibleValues.emplace(sumMid + sumRight);

			if (concatLeft != "" && concatRight != "")
				possibleValues.emplace(std::stoi(concatLeft) + sumMid + std::stoi(concatRight));
			else
				possibleValues.emplace(sumMid);

			possibleValues.emplace(sumLeft + std::stoi(concatMid) + sumRight);
			possibleValues.emplace(sumLeft + std::stoi(concatMid + concatRight));

			if (concatRight != "")
				possibleValues.emplace(sumLeft + sumMid + std::stoi(concatRight));
			else
				possibleValues.emplace(sumLeft + sumMid);

			possibleValues.emplace(sumLeft + sumMid + sumRight);
		}
	}

	std::cout << possibleValues.size() << '\n';

	system("pause");
}