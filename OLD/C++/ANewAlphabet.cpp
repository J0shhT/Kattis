#include <iostream>
#include <map>
#include <string>
#include <algorithm>

std::map<char, std::string> translations = {
	{ 'a', "@" },{ 'b', "8" },{ 'c', "(" },{ 'd', "|)" },{ 'e', "3" },{ 'f', "#" },{ 'g', "6" },{ 'h', "[-]" },{ 'i', "|" },{ 'j', "_|" },
	{ 'k', "|<" },{ 'l', "1" },{ 'm', "[]\\/[]" },{ 'n', "[]\\[]" },{ 'o', "0" },{ 'p', "|D" },{ 'q', "(,)" },{ 'r', "|Z" },{ 's', "$" },{ 't', "][" },
	{ 'u', "|_|" },{ 'v', "\\/" },{ 'w', "\\/\\/" },{ 'x', "}{" },{ 'y', "`/" },{ 'z', "2" }
};

int main()
{
	std::string text;
	std::getline(std::cin, text);
	std::transform(text.begin(), text.end(), text.begin(), ::tolower);
	for (char c : text)
	{
		if (translations.find(c) != translations.end())
		{
			std::cout << translations[c];
		}
		else
		{
			std::cout << c;
		}
	}
}