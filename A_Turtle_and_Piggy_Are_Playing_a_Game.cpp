#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int cur = 1;
        int ans = 0;
        while (cur <= r)
        {
            cur = cur * 2;
            ans++;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}