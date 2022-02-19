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
        int l, r, k;
        cin >> l >> r >> k;
        if (r - l == 0)
        {
            if (r < 2)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else if ((r - l) % 2)
        {
            if (k >= (r - l + 1) / 2)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            if (l % 2)
            {
                if (k >= (r - l + 2) / 2)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                if (k >= (r - l) / 2)
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
    return 0;
}