#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dis;
vector<int> parent;
int32_t main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    dis.assign(n + 1, 1e18);
    parent.resize(n + 1);
    dis[1] = 0;
    parent[1] = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    pq.push({0, 1});
    while (!pq.empty())
    {
        int distance_node = pq.top().first;
        int name_node = pq.top().second;
        pq.pop();
        for (auto child : adj[name_node])
        {
            if (dis[child.first] > distance_node + child.second)
            {
                dis[child.first] = distance_node + child.second;
                parent[child.first] = name_node;
                pq.push({dis[child.first], child.first});
            }
        }
    }
    if (dis[n] == 1e18)
    {
        cout << -1 << endl;
        return 0;
    }

    // cout<<dis[n]<<endl;
    vector<int> ans;
    while (n != 0)
    {
        ans.push_back(n);
        n = parent[n];
    }
    // cout<<1<<" ";
    reverse(ans.begin(), ans.end());
    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}