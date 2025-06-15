#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> slow(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        for (int i = 0; i < n; i++)
        {
            cin >> slow[i];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> dist(n, 1e18);
        dist[0] = 0;
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();


            for (auto it : adj[node])
            {
                if (dist[it.first] > dis + (it.second * slow[node]))
                {
                    dist[it.first] = dis + (it.second * slow[node]);
                    pq.push({dist[it.first], it.first});
                }
            }
        }

        cout << dist[n-1] << endl;
    }
    return 0;
}