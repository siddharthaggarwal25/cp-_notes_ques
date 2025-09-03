#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> w(n + 1), deg(n + 1);
        long long ans = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> w[i];
            ans += w[i];
        }

        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            deg[u]++, deg[v]++;
        }

        vector<int> extra;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < deg[i]; j++)
                extra.push_back(w[i]);
        }
        sort(extra.rbegin(), extra.rend());
        vector<long long> result;
        result.push_back(ans);

        for (int x : extra)
        {
            ans += x;
            result.push_back(ans);
        }

        // for (int i = 0; i < n - 1; i++) cout << result[i] << " ";
        cout << n << " " << result.size() << endl;
        // cout << "\n";
    }

    return 0;
}
