#include <cmath>
#include <iostream>
#include <limits>

static constexpr bool approximately(float a, float b)
{
	constexpr float epsilon = std::numeric_limits<float>::denorm_min() != 0 ? std::numeric_limits<float>::denorm_min()
																			: std::numeric_limits<float>::min();
	return std::abs(b - a) < std::max<float>(1e-6f * std::max<float>(std::abs(a), std::abs(b)), epsilon * 8);
}

static constexpr bool greaterOrEqual(float a, float b)
{
	return a > b || approximately(a, b);
}

static constexpr bool lessOrEqual(float a, float b)
{
	return a < b || approximately(a, b);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	float k;
	std::cin >> k;
	if (greaterOrEqual(k, 0) && lessOrEqual(k, 0.2f))
		std::cout << "Logn";
	else if (greaterOrEqual(k, 0.3f) && lessOrEqual(k, 1.5f))
		std::cout << "Andvari";
	else if (greaterOrEqual(k, 1.6f) && lessOrEqual(k, 3.3f))
		std::cout << "Kul";
	else if (greaterOrEqual(k, 3.4f) && lessOrEqual(k, 5.4f))
		std::cout << "Gola";
	else if (greaterOrEqual(k, 5.5f) && lessOrEqual(k, 7.9f))
		std::cout << "Stinningsgola";
	else if (greaterOrEqual(k, 8) && lessOrEqual(k, 10.7f))
		std::cout << "Kaldi";
	else if (greaterOrEqual(k, 10.8f) && lessOrEqual(k, 13.8f))
		std::cout << "Stinningskaldi";
	else if (greaterOrEqual(k, 13.9f) && lessOrEqual(k, 17.1f))
		std::cout << "Allhvass vindur";
	else if (greaterOrEqual(k, 17.2f) && lessOrEqual(k, 20.7f))
		std::cout << "Hvassvidri";
	else if (greaterOrEqual(k, 20.8f) && lessOrEqual(k, 24.4f))
		std::cout << "Stormur";
	else if (greaterOrEqual(k, 24.5f) && lessOrEqual(k, 28.4f))
		std::cout << "Rok";
	else if (greaterOrEqual(k, 28.5f) && lessOrEqual(k, 32.6f))
		std::cout << "Ofsavedur";
	else
		std::cout << "Farvidri";
	std::cout << std::endl;
}