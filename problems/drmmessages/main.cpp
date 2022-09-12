#include <iostream>
#include <string>
#include <tuple>
#include <utility>

std::pair<std::string, std::string> divide(const std::string& str)
{
	return {str.substr(0, str.length() / 2), str.substr(str.length() / 2)};
}

char rotate(char c, size_t rot)
{
	return char(((size_t(c - 'A') + rot) % 26) + 'A');
}

void rotate(std::string& str)
{
	size_t rot = 0;
	for (char c : str)
		rot += size_t(c - 'A');
	for (char& c : str)
		c = rotate(c, rot);
}

void merge(std::string& s1, const std::string& s2)
{
	for (size_t i = 0; i < s1.length(); ++i)
		s1[i] = rotate(s1[i], size_t(s2[i] - 'A'));
}

int main()
{
	std::string input;
	std::cin >> input;

	std::string s1, s2;
	std::tie(s1, s2) = divide(input);
	rotate(s1);
	rotate(s2);
	merge(s1, s2);

	std::cout << s1 << '\n';
}