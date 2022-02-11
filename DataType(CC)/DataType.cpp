
// Question Link -->> https://www.codechef.com/START25C/problems/DATATYPE

#include <iostream>
#include <stdlib.h>

using namespace std;

int dataType(int n, int x)
{
    if (x <= n)
    {
        return x;
    }
    else if (x > n && x - n <= n + 1)
    {
        return x - n - 1;
    }
    else
    {
        return dataType(n, x - n - 1);
    }
}

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n >> x;
        int res = dataType(n, x);
        cout << res << endl;
    }
    return 0;
}