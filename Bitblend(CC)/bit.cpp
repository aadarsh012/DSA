
// Question Link -->> https://www.codechef.com/problems/BITBLEND

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int parity(int x)
{
    return x % 2;
}

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
        vector<pair<int, int>> res1;
        vector<pair<int, int>> res2;
        bool odd = false, even = false;
        bool oddBit = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2)
            {
                oddBit = true;
                if (i % 2)
                {
                    odd = true;
                }
                else
                {
                    even = true;
                }
            }
        }
        if (!oddBit)
        {
            cout << -1 << endl;
        }
        else
        {
            if (odd)
            {
                int oddPos = -1;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] % 2 && i % 2)
                    {
                        oddPos = i;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    if (a[i] % 2 == 0 && i % 2)
                    {
                        res1.push_back({i + 1, oddPos + 1});
                    }
                    else if (a[i] % 2 && i % 2 == 0)
                    {
                        res1.push_back({i + 1, oddPos + 1});
                    }
                }
            }
            if (even)
            {
                int evenPos = -1;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] % 2 && i % 2 == 0)
                    {
                        evenPos = i;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    if (a[i] % 2 == 0 && i % 2 == 0)
                    {
                        res2.push_back({i + 1, evenPos + 1});
                    }
                    else if (a[i] % 2 && i % 2)
                    {
                        res2.push_back({i + 1, evenPos + 1});
                    }
                }
            }
            int ans1 = res1.size(), ans2 = res2.size();
            if (odd && even)
            {
                if (ans1 < ans2)
                {
                    cout << ans1 << endl;
                    for (int i = 0; i < res1.size(); i++)
                    {
                        cout << res1[i].first << " " << res1[i].second << endl;
                    }
                }
                else
                {
                    cout << ans2 << endl;
                    for (int i = 0; i < res2.size(); i++)
                    {
                        cout << res2[i].first << " " << res2[i].second << endl;
                    }
                }
            }
            else if (odd)
            {
                cout << ans1 << endl;
                for (int i = 0; i < res1.size(); i++)
                {
                    cout << res1[i].first << " " << res1[i].second << endl;
                }
            }
            else
            {
                cout << ans2 << endl;
                for (int i = 0; i < res2.size(); i++)
                {
                    cout << res2[i].first << " " << res2[i].second << endl;
                }
            }
        }
    }
    return 0;
}