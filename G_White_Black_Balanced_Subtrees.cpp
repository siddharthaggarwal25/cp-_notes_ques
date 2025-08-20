#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, int> dfs(int node, int par, int &ans, string &s, vector<vector<int>> &adj)
{

    pair<int, int> wb = {0, 0};
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        auto childWB = dfs(child, node, ans, s, adj);
        wb.first += childWB.first;
        wb.second += childWB.second;
    }
    if (s[node - 1] == 'W')
        wb.first++;
    else
        wb.second++;

    if (wb.first == wb.second)
        ans++;

    return wb;
    ;
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
        int ans = 0;
        dfs(1, -1, ans, s, adj);
        cout << ans << endl;
    }
    return 0;
}