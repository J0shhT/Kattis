#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
	int correct = 0;
	int score = 0;
	std::unordered_map<char, int> incorrect;
	int minutes;
	while (std::cin >> minutes && minutes != -1)
	{
		char problem;
		std::string result;
		std::cin >> problem >> result;
		if (result == "wrong")
		{
			incorrect[problem]++;
		}
		else if (result == "right")
		{
			correct++;
			score += minutes;
			if (incorrect.find(problem) != incorrect.end())
			{
				score += incorrect[problem] * 20;
			}
		}
	}
	std::cout << correct << ' ' << score;
}