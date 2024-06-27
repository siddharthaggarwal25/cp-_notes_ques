#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n];
        map<pair<int, int>, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            int aa = a[i] % x;
            int b = a[i] % y;
            ans += mp[{(x - aa) % x, b}];
            mp[{aa, b}]++;
        }
        cout << ans << endl;
    }
    return 0;
}