#include <iostream>
#include <string>

int main()
{
	std::string sequence;
	std::cin >> sequence;

	int count = 0;
	for (size_t start = 0; start < sequence.size(); start++)
	{
		char startCharacter = sequence[start];
		bool characters[128] = { false };
		for (size_t current = start + 1; current < sequence.size(); current++)
		{
			char currentCharacter = sequence[current];
			if (currentCharacter == startCharacter)
			{
				break;
			}
			if (characters[currentCharacter] == false)
			{
				count++;
			}
			characters[currentCharacter] = true;
		}
	}
	std::cout << count << "\n";
	return 0;
}