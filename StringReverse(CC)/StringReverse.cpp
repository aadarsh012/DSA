
// Question Link -->> https://www.codechef.com/START27C/problems/STR_REVERSE

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        int i = 0, j = 0;
        int res = 0;
        while (i < n)
        {
            if (s[i] == rev[j])
            {
                j++;
            }
            else
            {
                res++;
            }
            i++;
        }
        cout << res << endl;
    }
    return 0;
}