#include <iostream>
#include <string>

int main()
{
	static const char pattern[3] = {'P', 'E', 'R'};
	std::string str;
	std::cin >> str;

	size_t count = 0;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] != pattern[i % 3])
			++count;
	}

	std::cout << count << '\n';
}