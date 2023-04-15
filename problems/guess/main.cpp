#include <iostream>
#include <string>

// #define DEBUG_TESTING

struct State
{
	int Min = 0;
	int Max = 1001;

	int GetNextGuess()
	{
		return (Min + Max) / 2;
	}
};

int main()
{
#ifdef DEBUG_TESTING
	for (int answer = 1; answer < 1001; ++answer)
#endif
	{
		State state;
		int guess;

#ifdef DEBUG_TESTING
		int tries = 0;
#else
		std::string response;
#endif

		do
		{
			guess = state.GetNextGuess();

#ifdef DEBUG_TESTING
			++tries;
			if (guess > answer)
				state.Max = guess;
			else if (guess < answer)
				state.Min = guess;
#else
			std::cout << guess << std::endl;
			std::cin >> response;
			if (response == "lower")
				state.Max = guess;
			else if (response == "higher")
				state.Min = guess;
#endif
		}
#ifdef DEBUG_TESTING
		while (guess != answer);
#else
		while (response != "correct");
#endif

#ifdef DEBUG_TESTING
		std::cout << answer << " : " << tries << std::endl;
#endif
	}
}