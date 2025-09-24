#include <bits/stdc++.h>
using namespace std;
int dfs(int node, int parent, int &ans, vector<vector<int>> &adj)
{
    vector<int> temp;
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        int val = dfs(child, node, ans, adj);
        temp.push_back(val);
    }
    sort(temp.begin(), temp.end(), greater<>());
    if (temp.size() >= 2)
    {
        ans = max(ans, 2 + temp[0] + temp[1]);
    }
    if (temp.size() >= 1)
    { 
        ans = max( ans  , temp[0] +1);
        return 1 + temp[0];
    }

    return 0;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    dfs(1, -1, ans, adj);
    cout << ans << endl;
    return 0;
}