#include <iostream>
#include <string>

int main()
{
	std::string shortNames;
	std::string names;
	std::cin >> names;
	
	if (names.size() > 0)
	{
		shortNames += names[0];
		size_t currentIndex = names.find('-');
		while (currentIndex != std::string::npos)
		{
			shortNames += names[currentIndex + 1];
			currentIndex = names.find('-', currentIndex + 1);
		}
		std::cout << shortNames;
	}
}