#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;
	int vowelCount = 0, yCount = 0;
	for (const auto& ch : s)
	{
		if (ch == 'y')
			++yCount;
		else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			++vowelCount;
	}
	std::cout << vowelCount << ' ' << vowelCount + yCount << std::endl;
}