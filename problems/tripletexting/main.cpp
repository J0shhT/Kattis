#include <iostream>
#include <string>

int main()
{
	std::string textedWord;
	std::cin >> textedWord;

	size_t actualSize = textedWord.size() / 3;
	std::string actualWord;
	actualWord.reserve(actualSize);

	for (size_t i = 0; i < actualSize; i++)
	{
		char c1 = textedWord[i];
		char c2 = textedWord[i + actualSize];
		char c3 = textedWord[i + actualSize * 2];

		if (c1 == c2 || c1 == c3)
		{
			actualWord.push_back(c1);
		}
		else if (c2 == c3)
		{
			actualWord.push_back(c2);
		}
	}

	std::cout << actualWord << std::endl;
	return 0;
}


/*jnfbhjfgjfgjfghjfg
jhfgd
j
fgd
j
ghfd
j
hgd*/