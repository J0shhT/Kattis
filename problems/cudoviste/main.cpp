#include <iostream>
#include <string>

struct Map
{
	const size_t rows;
	const size_t cols;

	Map(size_t rows, size_t cols)
		: rows(rows)
		, cols(cols)
		, m_data(new char[rows * cols])
	{
		for (size_t y = 0; y < rows; ++y)
		{
			for (size_t x = 0; x < cols; ++x)
			{
				char c;
				do
					c = std::getchar();
				while (c == '\n');
				m_data[y * cols + x] = c;
			}
		}
	}

	int CountParkedCars(size_t x, size_t y)
	{
		size_t count = 0;
		for (size_t _y = y; _y <= y + 1; ++_y)
		{
			for (size_t _x = x; _x <= x + 1; ++_x)
			{
				char c = m_data[_y * cols + _x];
				if (c == 'X')
					++count;
				else if (c == '#')
					return -1;
			}
		}
		return count;
	}

private:
	char* m_data;
};

int main()
{
	int R, C;
	std::cin >> R >> C;
	Map map(R, C);

	size_t counts[5] = {0};
	for (size_t y = 0; y < map.rows - 1; ++y)
	{
		for (size_t x = 0; x < map.cols - 1; ++x)
		{
			auto count = map.CountParkedCars(x, y);
			if (count >= 0)
				++counts[count];
		}
	}

	for (size_t i = 0; i < sizeof(counts) / sizeof(*counts); ++i)
		std::cout << counts[i] << std::endl;
}