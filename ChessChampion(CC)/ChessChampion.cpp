// Questin Link -->> https://www.codechef.com/FEB222C/problems/WCC

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int x;
        cin >> x;
        int c = 0, n = 0;
        string s;
        cin >> s;
        for (int i = 0; i < 14; i++)
        {
            if (s[i] == 'C')
                c += 2;
            else if (s[i] == 'N')
                n += 2;
            else
            {
                c++;
                n++;
            }
        }
        if (c > n)
        {
            cout << 60 * x << endl;
        }
        else if (c == n)
        {
            cout << 55 * x << endl;
        }
        else
        {
            cout << 40 * x << endl;
        }
    }
}