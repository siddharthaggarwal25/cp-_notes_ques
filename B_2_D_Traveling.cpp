#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, a, b;
        cin >> n >> k >> a >> b;

        vector<pair<int, int>> v(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i].first >> v[i].second;

        if (a <= k && b <= k)
            cout << 0 << endl;
        else if ((a <= k && b > k) || (a > k && b <= k))
        {
            if (a > b) swap(a, b);
            int mini = abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);

            for (int i = 1; i <= k; i++)
            {
                mini = min(mini, abs(v[i].first - v[b].first) + abs(v[i].second - v[b].second));
            }
            cout << mini << endl;
        }
        else
        {
            int mini = abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
            int mini1 = 1e18;
            int mini2 = 1e18;
            for (int i = 1; i <= k; i++)
            {
                mini1 = min(mini1, abs(v[i].first - v[b].first) + abs(v[i].second - v[b].second));
                mini2 = min(mini2, abs(v[i].first - v[a].first) + abs(v[i].second - v[a].second));
            }

            cout << min(mini, mini1 + mini2) << endl;
        }
    }
    return 0;
}