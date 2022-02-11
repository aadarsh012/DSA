// Question -->> https://www.codechef.com/START25C/problems/EQUALMEX

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

// Sorting
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

int zerosCheck(vector<int> &a)
{
    int zero = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
        {
            zero++;
        }
    }
    return zero;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n * 2);
        for (int i = 0; i < n * 2; i++)
        {
            cin >> a[i];
        }
        int zeros = zerosCheck(a);
        if (zeros == 0)
        {
            cout << "YES" << endl;
        }
        else if (zeros == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            mergeSort(a, 0, n * 2 - 1);
            int largestSimilar = 1;
            for (int i = n * 2 - 2; i > n / 2; i--)
            {
                if (a[i] == a[n * 2 - 1])
                {
                    largestSimilar++;
                }
            }
            if (largestSimilar > 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}