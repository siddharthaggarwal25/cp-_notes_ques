#include <bits/stdc++.h>
using namespace std;
#define int long long 

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &weight, int mini, int maxi, vector<int> &ans)
{
    ans[node] = max(weight[node], mini * -1 + weight[node]);
    mini = min(weight[node], maxi * -1 + weight[node]);
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;

        dfs(child, node, adj, weight, mini, ans[node], ans);
    }
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> weight(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
            cin >> weight[i];
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin>>a>>b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> ans(n);
        dfs(0, -1, adj, weight, 0, 0, ans);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}