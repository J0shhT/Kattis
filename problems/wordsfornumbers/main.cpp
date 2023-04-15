#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

static std::unordered_map<int, std::string> translations = {
	{0, "zero"},      {1, "one"},       {2, "two"},       {3, "three"},    {4, "four"},     {5, "five"},
	{6, "six"},       {7, "seven"},     {8, "eight"},     {9, "nine"},     {10, "ten"},     {11, "eleven"},
	{12, "twelve"},   {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"},
	{18, "eighteen"}, {19, "nineteen"}, {20, "twenty"},   {30, "thirty"},  {40, "forty"},   {50, "fifty"},
	{60, "sixty"},    {70, "seventy"},  {80, "eighty"},   {90, "ninety"}};

static std::string translateNumber(int value, bool startWithCapital = false)
{
	std::string translation;
	auto directTranslation = translations.find(value);
	if (directTranslation != translations.cend())
	{
		translation = directTranslation->second;
	}
	else
	{
		int baseValue = (value / 10) * 10;
		translation += translations.at(baseValue);
		translation += '-';
		translation += translations.at(value % 10);
	}

	if (startWithCapital)
		translation[0] = std::toupper(translation[0]);
	return translation;
}

int main()
{
	std::string input;
	while (!std::getline(std::cin, input).eof())
	{
		std::vector<std::pair<size_t, size_t>> positions;
		for (int i = 0; i < input.length(); ++i)
		{
			char ch = input[i];
			if (ch < '0' || ch > '9')
				continue;

			std::pair<size_t, size_t> pos;
			pos.first = i;
			pos.second = 1;

			if (++i < input.length())
			{
				ch = input[i];
				if (ch >= '0' && ch <= '9')
					++pos.second;
			}

			positions.push_back(pos);
		}

		int offset = 0;
		for (const auto& position : positions)
		{
			auto start = position.first + offset;
			auto length = position.second;

			auto valueStr = input.substr(start, length);
			int value = std::atoi(valueStr.c_str());
			auto translation = translateNumber(value, start == 0);

			input.replace(start, length, translation);
			offset += translation.length() - length;
		}

		std::cout << input << std::endl;
	}
}