#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, 1e9);
    dis[1] = 0;
    pq.push({0, 1});

    vector<int> ans;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int currdis = pq.top().first;
        pq.pop();

        for (auto child : adj[node])
        {
            if (child.first == n)
                ans.push_back(currdis + child.second);
            if (dis[child.first] > child.second + currdis)
            {
                dis[child.first] = child.second + currdis;
                pq.push({dis[child.first], child.first});
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; i++)
        cout << ans[i] << " ";
    return 0;
}