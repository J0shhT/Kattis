#include <iostream>

int main()
{
	int participants;
	int budget;
	int hotels;
	int weeks;

	std::cin >> participants >> budget >> hotels >> weeks;

	int minPrice = 0;

	for (int hotel = 0; hotel < hotels; hotel++)
	{
		int price;
		std::cin >> price;
		for (int week = 0; week < weeks; week++)
		{
			int beds;
			std::cin >> beds;
			if (participants <= beds)
			{
				int totalPrice = participants * price;
				if (totalPrice <= budget)
				{
					if (minPrice == 0 || totalPrice < minPrice)
					{
						minPrice = totalPrice;
					}
				}
			}
		}
	}

	if (minPrice != 0)
	{
		std::cout << minPrice << std::endl;
	}
	else
	{
		std::cout << "stay home" << std::endl;
	}
	
	return 0;
}
