#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>
#include <cmath>

int calc(long long nCard)
{
    int PyramidHeight = 0;
    long double nNeededCardForPyramid, oldValue;
    do
    {
        oldValue = nNeededCardForPyramid;
        PyramidHeight++;
        nNeededCardForPyramid = 1.5*(float)PyramidHeight*(float)PyramidHeight + 0.5*(float)PyramidHeight;
        if (nNeededCardForPyramid > nCard)
        {
            return nCard - (long long) oldValue;
        }
        else if (nNeededCardForPyramid == nCard)
        {
            return 0;
        }
    } while(1);
}

int main()
{
    int testcase;
    std::cin >> testcase;
    std::vector<long long> nCard(testcase);
    for (int i = 0; i < testcase; i++)
    {
        std::cin >> nCard[i];
    }
    for (int i = 0; i < testcase; i++)
    {
        int nPyramid = 0;
        while (nCard[i] >= 2)
        {
            nCard[i] = calc(nCard[i]); 
            nPyramid++;
        }
        std::cout << nPyramid << std::endl;
    }
    return 0;
}
