#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> parent(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    vector<int> dis(n + 1, 1e9);
    dis[1] = 0;
    parent[0] = 0;
    parent[1] =0 ;  
    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto child : adj[node])
        {
            if (dis[child] > distance + 1)
            {
                dis[child] = distance + 1;
                parent[child] = node;
                pq.push({dis[child], child});
            }
        }
    }
    if (dis[n] == 1e9)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << dis[n] + 1 << endl;
        vector<int> ans;
        int node = n;
        while (node != 0)
        {
            ans.push_back(node);
            node = parent[node];
        }
        reverse(ans.begin(), ans.end());
        for (auto it : ans)
            cout << it << " ";
    }
    return 0;
}