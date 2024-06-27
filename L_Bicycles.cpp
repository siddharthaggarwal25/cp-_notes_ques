#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> slow(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n + 1, 1e9);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        };
        for (int i = 1; i <= n; i++)
        {
            cin >> slow[i];
        }
        dis[1] = 0;
        int bike = slow[1];
        pq.push({0, 1});
        while (!pq.empty())
        {
            int total_dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto child : adj[node])
            {
                if (dis[child.first] > total_dis + (bike * (child.second)))
                {
                    dis[child.first] = total_dis + (bike * (child.second));
                    pq.push({dis[child.first], child.first});
                }
            }
        }
      
    }
    return 0;
}