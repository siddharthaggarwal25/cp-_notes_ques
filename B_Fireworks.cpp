#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, m;
        cin >> a >> b >> m;
        int ans = 2;
        ans += (m) / a;
        ans += (m) / b;
        cout << ans << endl;
    }
    return 0;
}