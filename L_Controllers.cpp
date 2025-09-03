#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int q;
    cin >> q;

    int p = 0, m = 0;
    for (char c : s)
    {
        if (c == '+')
            p++;
        else
            m++;
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int tot = p - m;

        if (tot == 0)
        {
            cout << "YES\n";
            continue;
        }
        if (x == y)
        {
            cout << "NO\n";
            continue;
        }

        int num = tot * y;
        int den = y - x;

        if (num % den != 0)
        {
            cout << "NO\n";
            continue;
        }

        int k = num / den;
        if (k >= -m && k <= p)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
