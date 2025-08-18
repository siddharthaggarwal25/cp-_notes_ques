#include <bits/stdc++.h>
using namespace std;
#define int long long
int dfs(int node, int par, pair<int, int> &wb, string &s, vector<vector<int>> &adj)
{

    int cnt = 0;
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        cnt += dfs(child, node, wb, s, adj);
    }
    if (s[node - 1] == 'W')
        wb.first++;
    else
        wb.second++;
    if (wb.first == wb.second)
        return cnt + 1;

    return cnt;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 2; i <= n; i++)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        string s;
        cin >> s;
        pair<int, int> wb = {0, 0};

        int ans = dfs(1, -1, wb, s, adj);
        cout << ans << endl;
    }
    return 0;
}