#include <iostream>
#include <vector>

#include <chrono>

int main()
{
	int datasets;
	std::cin >> datasets;

	for (int i = 0; i < datasets; i++)
	{
		int n, m;
		std::vector<int> integers;

		std::cin >> n;
		std::cin >> m;

		for (int j = 0; j < n; j++)
		{
			int num;
			std::cin >> num;
			integers.push_back(num);
		}

		auto start = std::chrono::steady_clock::now();

		std::vector<std::vector<int>> possibleDatasets;

		int pushes = 0;
		for (int start = 0; start < n; start++)
		{
			if (integers[start] < m)
				continue;

			for (int end = n - 1; end >= start; end--)
			{
				if (integers[end] < m)
					continue;

				std::vector<int> dataset;
				bool mFound = false;
				bool isGood = true;
				for (int k = start; k <= end; k++)
				{
					int num = integers[k];
					if (num < m)
					{
						isGood = false;
						break;
					}
					else if (num == m)
					{
						if (mFound)
						{
							isGood = false;
							break;
						}
						else
						{
							mFound = true;
						}
					}
					dataset.push_back(num);
					pushes++;
				}
				if (isGood && mFound)
				{
					possibleDatasets.push_back(dataset);
				}
			}
		}

		int maxWeight = 0;
		for (auto& ds : possibleDatasets)
		{
			int weight = 0;
			for (int& num : ds)
			{
				weight += num;
			}
			if (weight > maxWeight)
			{
				maxWeight = weight;
			}
		}

		std::cout << maxWeight << "\n";

		auto end = std::chrono::steady_clock::now();
		auto diff = end - start;
		auto diff_sec = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
		std::cout << diff_sec.count() / 1000.0 << "s\n";
		std::cout << "pushes: " << pushes << "\n";
	}

	getchar();
	getchar();
}