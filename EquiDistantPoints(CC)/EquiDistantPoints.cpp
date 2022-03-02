
// Question Link -->> https://www.codechef.com/LTIME105C/problems/DISTCON

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int D;
    cin >> D;
    if (D % 2 == 0)
    {
        cout << D / 2 << " " << 0 << endl;
        cout << 0 << " " << D / 2 << endl;
        cout << "-" << D / 2 << " " << 0 << endl;
        cout << 0 << " "
             << "-" << D / 2 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}