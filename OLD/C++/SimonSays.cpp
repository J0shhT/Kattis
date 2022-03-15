#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string cases;
	std::getline(std::cin, cases);

	std::string simonSays = "Simon says";

	for (int i = 0; i < std::stoi(cases); i++)
	{
		std::string text;
		std::getline(std::cin, text);
		auto iter = std::search(text.begin(), text.end(), simonSays.begin(), simonSays.end());
		if (iter != text.end())
		{
			text.erase(iter, iter + simonSays.size());
			std::cout << text << "\n";
		}
	}
}