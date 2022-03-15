#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

int main()
{
	int N;
	std::cin >> N;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int total = 0;
	while (N--)
	{
		std::string input;
		std::getline(std::cin, input);
		std::for_each(input.begin(), input.end(), [&](char &c) { c = std::tolower(c); });
		//std::cout << input << std::endl;
		if (input.find("pink") != std::string::npos || input.find("rose") != std::string::npos) ++total;
	}
	if (total != 0)
		std::cout << total << std::endl;
	else
		std::cout << "I must watch Star Wars with my daughter" << std::endl;
	return 0;
}