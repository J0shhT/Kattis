#include <iostream>

class AdjacencyMatrix
{
public:
	AdjacencyMatrix() = delete;
	explicit AdjacencyMatrix(std::istream& input, int n)
		: m_length(n)
		, m_size(m_length * m_length)
		, m_data(new bool[m_size])
	{
		for (int i = 0; i < m_size; ++i)
			std::cin >> m_data[i];
	}

	~AdjacencyMatrix()
	{
		delete[] m_data;
	}

	const bool& ElementAt(int x, int y) const
	{
		return m_data[y * m_length + x];
	}

	bool IsAdjacent(int v1, int v2) const
	{
		return ElementAt(v2, v1) == true;
	}

	bool IsWeak(int v) const
	{
		for (int j = 0; j < m_length; ++j)
		{
			if (v == j || !IsAdjacent(v, j))
				continue;
			for (int k = 0; k < m_length; ++k)
			{
				if (v == k || j == k || !IsAdjacent(v, k))
					continue;
				if (IsAdjacent(j, k))
					return false;
			}
		}

		return true;
	}

private:
	const int m_length;
	const int m_size;
	bool* m_data;
};

int main()
{
	int n;
	while (std::cin >> n, n != -1)
	{
		AdjacencyMatrix graph(std::cin, n);

		bool hasWeakVertex = false;
		for (int i = 0; i < n; ++i)
		{
			if (graph.IsWeak(i))
			{
				if (hasWeakVertex)
					std::cout << ' ';
				std::cout << i;
				hasWeakVertex = true;
			}
		}
		std::cout << std::endl;
	}
}