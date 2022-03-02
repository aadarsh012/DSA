
// Question Link -->> https://www.codechef.com/submit/PLPROCESS

#include <bits/stdc++.h>
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
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        long long sumLeft = 0;
        long long sumRight = sum;
        long long res = sum;
        if (n > 1)
        {
            for (int i = 0; i < n; i++)
            {
                sumLeft += a[i];
                sumRight -= a[i];
                res = min(res, max(sumLeft, sumRight));
            }
        }
        cout << res << endl;
    }
}