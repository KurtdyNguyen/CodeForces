#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int main(){
    int testcase, a1, a2, a3, a4;
    cin >> testcase;
    while(testcase--)
    {
        cin >> a1 >> a2 >> a3 >> a4;
        if (a1 == 0)
            cout << 1 << endl;
        else
            cout << a1 + 2 * min(a2, a3) + min(a1 + 1, abs(a2 - a3) + a4) << endl;
    }
    return 0;
}
