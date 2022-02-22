
// Question Link -->> https://www.codechef.com/COOK138C/problems/PREFPERM

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
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        mergeSort(a, 0, k - 1);
        for (int i = a[0]; i > 0; i--)
        {
            cout << i << " ";
        }
        for (int i = 1; i < k; i++)
        {
            for (int j = a[i]; j > a[i - 1]; j--)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
