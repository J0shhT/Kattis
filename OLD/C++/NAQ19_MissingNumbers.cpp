#include <iostream>
#include <map>
#include <unordered_set>

int main()
{
    int max = 1;
    int n;
    std::cin >> n;

    std::unordered_set<int> numbers;
    numbers.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        numbers.emplace(num);
        if (num > max)
        {
            max = num;
        }
    }

    bool won = true;
    for (int i = 1; i <= max; i++)
    {
        if (numbers.find(i) == numbers.end())
        {
            std::cout << i << "\n";
            won = false;
        }
    }

    if (won)
    {
        std::cout << "good job\n";
    }


    return 0;
}