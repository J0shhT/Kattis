#include <iostream>
#include <string>

int main()
{
	std::string input;
	int line = 1;
	while (!std::cin.eof() && std::getline(std::cin, input))
	{
		if (input == "END") break;
		int spacing = -1;
		int count = 0;
		bool bad = false;
		bool isStart = true;
		for (char c : input)
		{
			if (c == '.')
			{
				++count;
			}
			else
			{
				if (count == 0 && spacing < 0 && isStart)
				{
					isStart = false;
					continue;
				}
				if (spacing < 0)
				{
					spacing = count;
				}
				if (count != spacing)
				{
					bad = true;
					break;
				}
				count = 0;
				isStart = false;
			}
		}
		std::cout << line++ << ' ' << (bad ? "NOT EVEN" : "EVEN") << std::endl;
	}
	return 0;
}