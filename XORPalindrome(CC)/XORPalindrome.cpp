
// Question Link -->> https://www.codechef.com/FEB222C/problems/XORPAL

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n % 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            int zeros = 0, ones = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                    zeros++;
                else
                    ones++;
            }
            if (zeros == 0 || ones == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                if (zeros == ones)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}