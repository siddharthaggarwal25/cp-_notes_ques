#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int check = (a + b + c) / 9;
        if ((a + b + c) % 9 == 0 && a - check >= 0 && b - check >= 0 && c - check >= 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO"
        }
    }

    return 0;
}