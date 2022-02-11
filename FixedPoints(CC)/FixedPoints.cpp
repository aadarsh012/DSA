// Question Link -->> https://www.codechef.com/FEB222C/problems/NOFIX

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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int i = 0, ops = 0;
        while (i < n)
        {
            if (a[i] == i + 1 + ops)
            {
                ops++;
            }
            i++;
        }
        cout << ops << endl;
    }
    return 0;
}