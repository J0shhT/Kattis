#include <iostream>
#include <limits>

struct LineState
{
	char PreviousColor = '\0';
	size_t Consecutives = 0;
};

class Grid
{
public:
	Grid() = delete;

	explicit Grid(size_t size)
		: m_size(size)
		, m_rowDelta(new int[m_size])
		, m_colDelta(new int[m_size])
		, m_colStates(new LineState[m_size])
		, m_valid(true)
	{
		for (size_t y = 0; y < m_size; ++y)
		{
			RowDelta(y) = 0;
			m_rowState = LineState();

			for (size_t x = 0; x < m_size; ++x)
			{
				if (y == 0)
					ColumnDelta(x) = 0;

				char color;
				std::cin >> color;
				RowDelta(y) += color == 'W' ? 1 : -1;
				ColumnDelta(x) += color == 'W' ? 1 : -1;

				if (m_rowState.PreviousColor == color)
					++m_rowState.Consecutives;
				else
					m_rowState.Consecutives = 1;
				m_rowState.PreviousColor = color;

				auto& state = ColumnState(x);
				if (state.PreviousColor == color)
					++state.Consecutives;
				else
					state.Consecutives = 1;
				state.PreviousColor = color;

				if (state.Consecutives >= 3)
					m_valid = false;
			}

			if (RowDelta(y) != 0 || m_rowState.Consecutives >= 3)
				m_valid = false;

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		for (size_t x = 0; x < m_size; ++x)
		{
			if (ColumnDelta(x) != 0)
			{
				m_valid = false;
				break;
			}
		}
	}

	~Grid()
	{
		delete[] m_rowDelta;
		delete[] m_colDelta;
		delete[] m_colStates;
	}

	int& RowDelta(size_t y)
	{
		return m_rowDelta[y];
	}

	int& ColumnDelta(size_t x)
	{
		return m_colDelta[x];
	}

	LineState& ColumnState(size_t x)
	{
		return m_colStates[x];
	}

	bool IsValid() const
	{
		return m_valid;
	}

private:
	const size_t m_size;

	int* m_rowDelta;
	int* m_colDelta;

	LineState m_rowState;
	LineState* m_colStates;

	bool m_valid;
};

int main()
{
	int n;
	std::cin >> n;
	Grid grid(n);
	std::cout << (grid.IsValid() ? 1 : 0) << std::endl;
}