#include <iostream>
#include <string>

template<typename T>
struct Grid
{
	Grid(int rows, int cols)
		: rsize(rows), csize(cols)
	{
		grid = (T*)calloc(cols*rows, sizeof(T));
	}
	~Grid()
	{
		grid = (free(grid), nullptr);
	}
	void set(int row, int col, T value)
	{
		grid[row*csize + col] = value;
	}
	T get(int row, int col)
	{
		return grid[row*csize + col];
	}
	bool valid(int row, int col)
	{
		return row >= 0 && row < rsize && col >= 0 && col < csize;
	}
	int rsize;
	int csize;
	T* grid;
};

int main()
{
	int r, c;
	std::cin >> r >> c;
	Grid<char> map(r, c);
	Grid<bool> visited(r, c);
	std::getchar();
	for (int y = 0; y < r; ++y)
	{
		std::string line;
		std::getline(std::cin, line);
		for (int x = 0; x < c; ++x)
		{
			map.set(y, x, line[x]);
			visited.set(y, x, false);
		}
	}
	int moves = 0;
	bool won = false;
	int x = 0;
	int y = 0;
	while (map.valid(y, x))
	{
		char dir = map.get(y, x);
		visited.set(y, x, true);
		switch (dir)
		{
			case 'N':
				--y;
				break;
			case 'S':
				++y;
				break;
			case 'W':
				--x;
				break;
			case 'E':
				++x;
				break;
			case 'T':
				won = true;
				break;
			default:
				break;
		}
		if (won)
		{
			std::cout << moves << std::endl;
			return 0;
		}
		if (visited.valid(y, x) && visited.get(y, x))
		{
			std::cout << "Lost" << std::endl;
			return 0;
		}
		++moves;
	}
	std::cout << "Out" << std::endl;
}