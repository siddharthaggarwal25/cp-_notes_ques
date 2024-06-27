#include <bits/stdc++.h>
using namespace std;
int ans = 0;
vector<int> cur;
void dfs(int node, int parent, vector<vector<int>> &adj)
{

    for (auto child : adj[node])
    {
        if (child != parent)
            dfs(child, node, adj);
        if (!cur[node] && !cur[child])
        {
            cur[node] = 1;
            cur[child] = 1;
            ans++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cur.assign(n + 1, 0);
    // for( int i=0 ;i<=n ;i++)cout<<cur[i];
    dfs(1, 0, adj);
    cout << ans << endl;
    return 0;
}