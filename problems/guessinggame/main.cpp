#include <iostream>
#include <limits>

struct State
{
	int Min = 0;
	int Max = 11;
};

int main()
{
	State state;
	int guess;
	for (std::cin >> guess; guess != 0; std::cin >> guess)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::string response;
		std::getline(std::cin, response);

		if (response == "too high")
		{
			if (guess < state.Max)
				state.Max = guess;
		}
		else if (response == "too low")
		{
			if (guess > state.Min)
				state.Min = guess;
		}
		else if (response == "right on")
		{
			if (guess > state.Min && guess < state.Max)
				std::cout << "Stan may be honest\n";
			else
				std::cout << "Stan is dishonest\n";

			state = State();
		}
	}
}