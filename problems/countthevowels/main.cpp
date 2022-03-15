#include <iostream>

bool isVowel(char ch)
{
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I'
		   || ch == 'O' || ch == 'U';
}

int main()
{
	int count = 0;
	std::string s;
	std::getline(std::cin, s);
	for (char ch : s)
	{
		if (isVowel(ch))
			++count;
	}
	std::cout << count << '\n';
}