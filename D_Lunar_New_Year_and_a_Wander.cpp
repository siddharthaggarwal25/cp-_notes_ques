#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> vis(n + 1, -1);
    vector<int> ans;
    pq.push(1);

    while (!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        if (vis[node] == 1)
            continue;
        vis[node] =1 ;
        ans.push_back( node);    
        for (auto it : adj[node])
        {
            if (vis[it] == -1)
            {  
                pq.push( it);
            }
        }
    }

    for( auto it : ans)cout<<it<<" ";

    return 0;
}