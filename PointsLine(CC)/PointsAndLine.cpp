
// Question Link -->> https://www.codechef.com/START25C/problems/POLIN

#include <iostream>
#include <stdlib.h>
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
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        mergeSort(x, 0, n - 1);
        mergeSort(y, 0, n - 1);

        int i = 0;
        int hor = 0, ver = 0;
        while (i < n)
        {
            int j = i + 1;
            while (x[j] == x[i] && j < n)
            {
                j++;
            }
            i = j;
            hor++;
        }

        int k = 0;
        while (k < n)
        {
            int j = k + 1;
            while (y[j] == y[k] && j < n)
            {
                j++;
            }
            k = j;
            ver++;
        }
        cout << hor + ver << endl;
    }
    return 0;
}