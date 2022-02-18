// // Question Link -->> https://www.codechef.com/FEB222C/problems/BITSWAPS

// #include <iostream>
// #include <string>
// #include <vector>
// #include <stdlib.h>

// using namespace std;

// int main()
// {
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         int zeroPos = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (a[i] == 0)
//             {
//                 zeroPos = i;
//             }
//         }
//         if (zeroPos != 0)
//         {
//             cout << "NO" << endl;
//         }
//         else
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 int minimum = a[i];
//                 int maximum = a[i];
//                 int minSwap = a[i];
//                 int maxSwap = a[i];
//                 int minSwapPos = i, maxSwapPos = i;
//                 for (int j = 0; j < n; j++)
//                 {
//                     if (j < i)
//                     {
//                         maximum = max(maximum, a[j]);
//                         if ((a[j] & a[i]) != 0)
//                         {
//                             if (a[j] > maxSwap)
//                             {
//                                 maxSwap = a[j];
//                                 maxSwapPos = j;
//                             }
//                         }
//                     }
//                     if (j > i)
//                     {
//                         minimum = min(minimum, a[j]);
//                         if ((a[i] & a[j]) != 0)
//                         {
//                             if (a[j] < minSwap)
//                             {
//                                 minSwap = a[j];
//                                 minSwapPos = j;
//                             }
//                         }
//                     }
//                 }
//                 if (maxSwapPos == minSwapPos)
//                 {
//                     if (maximum > a[maxSwapPos] || minimum < a[minSwapPos])
//                     {
//                         cout << "NO" << endl;
//                         break;
//                     }
//                     else
//                     {
//                         cout << "YES" << endl;
//                         break;
//                     }
//                 }
//                 else if (maxSwap > a[i])
//                 {
//                     swap(a[i], a[maxSwapPos]);
//                 }
//                 else if (minSwap < a[i])
//                 {
//                     swap(a[i], a[minSwapPos]);
//                 }
//                 else
//                 {
//                     cout << "NO" << endl;
//                     break;
//                 }
//             }
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string reverse(string s)
{
    string temp = s;
    for (int i = 0; i < s.length() / 2; i++)
    {
        swap(temp[i], temp[s.length() - i - 1]);
    }
    return temp;
}

string invert(string s)
{
    string temp = s;
    for (int i = 0; i < s.length(); i++)
    {
        if (temp[i] == '1')
        {
            temp[i] = '0';
        }
        else
        {
            temp[i] = '1';
        }
    }
    return temp;
}

char kthBit(string s, int n, int k)
{
    string temp = s;
    if (n == 1)
    {
        return temp[k - 1];
    }
    temp = s + '1' + reverse(invert(s));
    return kthBit(temp, n - 1, k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    string s = "0";
    cout << kthBit(s, n, k) << endl;
    return 0;
}