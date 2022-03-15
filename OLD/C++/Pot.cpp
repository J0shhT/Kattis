#include <iostream>
#include <string>
#include <cmath>

int main()
{
	int answer = 0;
	int N = 0;

	std::cin >> N;
	for (; N > 0; N--)
	{
		std::string input;
		std::cin >> input;
		int power = (int)(input.back() - '0');
		input.pop_back();
		int num = std::stoi(input);
		answer += pow(num, power);
	}

	std::cout << answer << std::endl;

	return 0;
}