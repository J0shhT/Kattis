#include <iostream>
#include <string>

int guess(const std::string& password)
{
	std::cout << password << std::endl;
	std::string response;
	std::getline(std::cin, response);

	size_t pos1 = response.find_first_of('(');
	if (pos1 == std::string::npos)
		return 0;

	size_t pos2 = response.find_first_of(' ', pos1 + 1) - 1;
	std::string timeStr = response.substr(pos1 + 1, pos2 - pos1);
	return std::atoi(timeStr.c_str());
}

size_t findLength()
{
	std::string dummyGuess;
	dummyGuess.reserve(20);
	for (size_t i = 1; i <= 20; ++i)
	{
		dummyGuess += 'A';
		int timing = guess(dummyGuess);
		if (timing == 0)
			std::exit(0);
		else if (timing > 5)
			return i;
	}
	return 0;
}

static const char GUESS_TABLE[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
								   'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F',
								   'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
								   'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void guessNextCharacter(std::string& sourceStr, int targetLength)
{
	std::string guessStr = sourceStr;
	guessStr.reserve(targetLength);

	size_t numExtraChars = targetLength - sourceStr.length();
	for (size_t i = 0; i < numExtraChars; ++i)
		guessStr += 'a';

	size_t targetIndex = sourceStr.length();
	int maxTime = 0;
	char guessCh = 0;
	for (size_t i = 0; i < 62; ++i)
	{
		char ch = GUESS_TABLE[i];
		guessStr[targetIndex] = ch;

		int timing = guess(guessStr);
		if (timing == 0)
			std::exit(0);

		if (maxTime == 0)
		{
			guessCh = ch;
			maxTime = timing;
			continue;
		}

		if (timing > maxTime)
		{
			guessCh = ch;
			break;
		}
		else if (timing < maxTime)
			break;
	}

	sourceStr += guessCh;
}

int main()
{
	size_t length = findLength();
	std::string password = "";
	while (password.length() < length)
		guessNextCharacter(password, length);
}