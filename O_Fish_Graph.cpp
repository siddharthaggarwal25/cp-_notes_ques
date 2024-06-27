#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &order)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child])
            continue;
        dfs(child, adj, vis, order);
    }
    order.push_back(node);
}
void dfs2(int node, vector<int> &comp, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;
    comp.push_back(node);
    for (auto child : adj[node])
    {
        if (vis[child])
            continue;
        dfs2(child, comp, adj, vis);
    }
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n + 1, 0);
        vector<int> order;
        dfs(1, adj, vis, order);
        reverse(order.begin(), order.end());
        for (int i = 0; i <= n; i++)
            vis[i] = 0;
        vector<vector<int>> components;

        for (auto x : order)
        {
            if (vis[x])
                continue;
            vector<int> comp;
            dfs2(x, comp  , adj   , vis );
            components.push_back(comp);
        }

        for( auto comp : components){
            for( auto ele : comp)  cout<<ele<<" ";
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}