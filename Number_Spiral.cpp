#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int y, x;
        cin >> y >> x;

        if (y > x)
        {

            if (y % 2 == 0)
            {
                cout << (y * y) - x + 1 << endl;
            }
            else
            {
                y--;
                cout << (y * y) + x << endl;
            }
        }
        else
        {

            if (x % 2 == 1)
            {
                cout << x * x - y + 1 << endl;
            }
            else
            {
                x--;
                cout << x * x + y << endl;
            }
        }
    }
    return 0;
}