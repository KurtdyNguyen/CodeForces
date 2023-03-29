#include <iostream>
#include <vector>

int main()
{
    int testcase;
    std::cin >> testcase;
    std::vector<int> height(testcase), width(testcase);
    for (int i=0; i<testcase; i++)
    {
        std::cin >> height[i] >> width[i];
    }

    for (int i=0; i<testcase; i++)
    {
        if ((long long)height[i]*(long long)width[i] < ((long long)height[i] - 1) * (long long)width[i] + (long long)height[i] * ((long long)width[i] - 1))
        {
            std::cout << "NO\n";
        }
        else
            std::cout << "YES\n";
    }
    return 0;
}
