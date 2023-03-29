#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int testcase, monsters;
    cin >> testcase;
    while(testcase--)
    {
        cin >> monsters;
        int counter1 = 0;
        for (int j = 0; j < monsters; j++)
        {
            int hp;
            cin >> hp;
            if (hp == 1)
                counter1++;   
        }
        cout << monsters - counter1/2 << endl;
    }
    return 0;
}
