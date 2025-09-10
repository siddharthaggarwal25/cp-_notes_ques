#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int ans = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            ans += (m * v[i]);
            m--;
            m = max(m, 0LL);
        }
        cout << ans << endl;
    }

    return 0;
}