#include <iostream>
#include <string>

int main()
{
	int N;
	std::cin >> N;
	std::string beforeStr, afterStr;
	std::cin >> beforeStr >> afterStr;

	bool success = true;
	auto beforeIter = beforeStr.cbegin();
	auto afterIter = afterStr.cbegin();
	for (; beforeIter != beforeStr.cend() && afterIter != afterStr.cend(); ++beforeIter, ++afterIter)
	{
		auto before = *beforeIter;
		auto after = *afterIter;
		if ((N % 2 == 0 && before != after) || (N % 2 != 0 && before == after))
		{
			success = false;
			break;
		}
	}

	std::cout << (success ? "Deletion succeeded" : "Deletion failed") << std::endl;
}