
// Question Link -->> https://www.codechef.com/START27C/problems/BINSTRING

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
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1])
            {
                res++;
            }
        }
        cout << res + 1 << endl;
    }
    return 0;
}