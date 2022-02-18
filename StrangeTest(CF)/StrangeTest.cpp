
// Question Link -->> https://codeforces.com/contest/1632/problem/C

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        int power, powerA;
        int min1 = 999999, min2 = 999999, min3 = 999999;
        if ((a | b) == b)
        {
            cout << 1 << endl;
        }
        else
        {

            for (int i = 1; i <= b / 2 + 1; i++)
            {
                if (pow(2, i) > b)
                {
                    power = i;
                    break;
                }
            }
            for (int i = 1; i <= a / 2 + 1; i++)
            {
                if (pow(2, i) > a)
                {
                    powerA = i;
                    break;
                }
            }

            for (int i = b; i < pow(2, power); i++)
            {
                if ((a | i) == i)
                {
                    min1 = min(b - a, i - b + 1);
                    break;
                }
            }

            for (int i = a; i < b; i++)
            {
                if ((i | b) == b)
                {
                    min3 = i - a + 1;
                    break;
                }
            }

            int j = a;
            while (true)
            {
                if (ceil(log2(j)) == floor(log2(j)))
                {
                    break;
                }
                j++;
            }
            for (int i = b; i < pow(2, power); i++)
            {
                if ((j | i) == i)
                {
                    min2 = min(b - a, (i - b) + (j - a) + 1);
                    break;
                }
            }

            cout << min(min1, min(min2, min3)) << endl;
        }
    }
    return 0;
}
