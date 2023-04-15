#include <iostream>
#include <sstream>
#include <string>

int main()
{
	std::string inputStr;
	std::cin >> inputStr;
	std::stringstream input(inputStr);

	int numbers[3] = {0};
	std::string numStr;
	int i = 0;
	while (std::getline(input, numStr, '/'))
	{
		while (numStr.front() == '0')
			numStr.erase(0, 1);
		if (numStr.empty())
			numbers[i++] = 0;
		else
			numbers[i++] = std::stoi(numStr);
	}

	if (numbers[0] > 12)
		std::cout << "EU";
	else if (numbers[1] > 12)
		std::cout << "US";
	else
		std::cout << "either";
	std::cout << std::endl;
}