// Question Link -->> https://www.codechef.com/problems/ANTI_PAL

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(string &s, int start, int mid, int end)
{
    int i = start, j = mid + 1;
    vector<char> c;
    while (i <= mid && j <= end)
    {
        if (s[i] < s[j])
        {
            c.push_back(s[i++]);
        }
        else
        {
            c.push_back(s[j++]);
        }
    }
    while (i <= mid)
    {
        c.push_back(s[i++]);
    }
    while (j <= end)
    {
        c.push_back(s[j++]);
    }
    for (int k = start; k <= end; k++)
    {
        s[k] = c[k - start];
    }
}

void mergeSort(string &s, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(s, start, mid);
    mergeSort(s, mid + 1, end);
    merge(s, start, mid, end);
}

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n % 2 != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            int counter = 1;
            mergeSort(s, 0, n - 1);
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == s[i + 1])
                {
                    counter++;
                    if (counter > n / 2)
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    flag = 0;
                    counter = 1;
                }
            }
            if (flag == 1)
            {
                cout << "NO" << endl;
            }
            else
            {
                int j = n - 1;
                for (int i = 0; i < n / 2; i++)
                {
                    if (s[i] == s[n - i - 1])
                    {
                        char temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                        j--;
                    }
                }
                cout << "YES" << endl;
                cout << s << endl;
            }
        }
    }
    return 0;
}
