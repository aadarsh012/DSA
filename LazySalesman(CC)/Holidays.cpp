
// Question Link -->> https://www.codechef.com/COOK138C/problems/HOLIDAYS

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

void merge(vector<int> &a, int start, int mid, int end)
{
    int i = start, j = mid + 1;
    vector<int> res;
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            res.push_back(a[i++]);
        }
        else
        {
            res.push_back(a[j++]);
        }
    }

    while (i <= mid)
    {
        res.push_back(a[i++]);
    }
    while (j <= end)
    {
        res.push_back(a[j++]);
    }
    for (int k = start; k <= end; k++)
    {
        a[k] = res[k - start];
    }
}

void mergeSort(vector<int> &a, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    else
    {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, w, sum = 0, work = 0;
        cin >> n >> w;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == w)
        {
            cout << 0 << endl;
        }
        else
        {
            sum = 0;
            mergeSort(a, 0, n - 1);
            for (int i = n - 1; i >= 0; i--)
            {
                sum += a[i];
                work++;
                if (sum >= w)
                {
                    cout << n - work << endl;
                    break;
                }
            }
        }
    }
    return 0;
}