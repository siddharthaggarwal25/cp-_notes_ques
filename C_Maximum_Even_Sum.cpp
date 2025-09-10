#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (a % 2 == 1 && b % 2 == 1)
        {
            cout << a * b + 1 << endl;
        }
        else if (a % 2 == 0 && b % 2 == 0)
        {
            cout << (a * (b / 2) + 2) << endl;
        }
        else if (a % 2 == 0 && b % 2 == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            if (b % 4 == 0)
                cout << (a * (b / 2) + 2) << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}