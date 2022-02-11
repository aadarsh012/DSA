#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        int n, k;
        cin >> n >> k;
        cin >> s;
        int count = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
            {
                count++;
            }
        }
        if (count == k)
        {
            cout << "YES" << endl;
        }
        else if (count < k)
        {
            if ((k - count) % 2 == 0)
            {
                cout << "YES" << endl;
            }
            else if (n % 2 == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}