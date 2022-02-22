
// Question Link -->> https://www.codechef.com/COOK138C/problems/PERFPERM

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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }
        if (n == k)
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else
        {
            int temp = a[n - k];
            for (int i = n - k; i > 0; i--)
            {
                a[i] = a[i - 1];
            }
            a[0] = temp;
            for (auto elem : a)
            {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
    return 0;
}