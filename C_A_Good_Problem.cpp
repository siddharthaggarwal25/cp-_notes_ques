#include <bits/stdc++.h>
using namespace std;
#define int long long

int findNextNonOverlapping(int n)
{
    int mask = ~n;
    int lowest_available_bit = mask & -mask;
    int x = (n | lowest_available_bit);
    x &= ~(lowest_available_bit - 1);
    return x;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r, k;
        cin >> n >> l >> r >> k;

        if (n % 2 == 1)
        {
            cout << l << endl;
        }
        else if (n == 2)
        {
            cout << -1 << endl;
        }
        else
        {
            int res = 1;
            bool fl = 0;
            while (res <= r)
            {
                if (res > l)
                {
                    fl = 1;
                    if (k <= n - 2)
                        cout << l << endl;
                    else
                        cout << res << endl;
                    break;
                }
                res *= 2;
            }
            if (!fl)
                cout << -1 << endl;
        }
    }
    return 0;
}