
// Question Link -->> https://www.codechef.com/START26C/problems/SMOKE

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

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
        int n, x, y;
        cin >> n >> x >> y;
        int minSmoke = 999999, i, j;
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n; j++)
            {
                int k = 100 * i + 4 * j;
                if (k >= n)
                {
                    minSmoke = min(minSmoke, i * x + j * y);
                }
            }
        }
        cout << minSmoke << endl;
    }
    return 0;
}