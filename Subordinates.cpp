#include <bits/stdc++.h>
using namespace std;
#define int long long 

int dfs(int node, vector<int> &ans, vector<vector<int>> &adj)
{
    int cnt = 0;
    for (auto child : adj[node])
    {
        cnt += dfs(child, ans, adj);
    }
    ans[node] = cnt;
    return cnt + 1;
}
int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    vector<int> ans(n + 1, 0);
     dfs(1, ans, adj);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}