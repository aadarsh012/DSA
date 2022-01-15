#include <iostream>
#include <vector>

using std::vector;

using namespace std;

void Merge(vector<int> &a, int start, int mid, int end)
{
    int i = start, j = mid + 1;
    vector<int> c;

    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(a[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        c.push_back(a[i]);
        i++;
    }
    while (j <= end)
    {
        c.push_back(a[j]);
        j++;
    }

    for (int k = start; k <= end; k++)
    {
        a[k] = c[k - start];
    }
}

void MergeSort(vector<int> &a, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    MergeSort(a, start, mid);
    MergeSort(a, mid + 1, end);
    Merge(a, start, mid, end);
}

int main()
{
    int n, k;
    cout << "Enter Size of array: ";
    cin >> n;
    cout << "Enter K to find kth smallest: ";
    cin >> k;
    cout << "Enter Elements of array: " << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    MergeSort(arr, 0, n - 1);

    cout << arr[k - 1] << endl;
    return 0;
}