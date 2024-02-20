#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	std::string s1, s2;
	std::getline(std::cin, s1);
	std::getline(std::cin, s2);
	auto sep1 = std::find(s1.cbegin(), s1.cend(), '|');
	auto sep2 = std::find(s2.cbegin(), s2.cend(), '|');

	std::string output;
	auto iter = std::back_inserter(output);
	iter = std::copy(s1.cbegin(), sep1, iter);
	iter = std::copy(s2.cbegin(), sep2, iter);
	output += ' ';
	iter = std::back_inserter(output);
	iter = std::copy(std::next(sep1), s1.cend(), iter);
	iter = std::copy(std::next(sep2), s2.cend(), iter);
	std::cout << output << std::endl;
}