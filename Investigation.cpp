#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, 1e9);
    dis[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int curdis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto child : adj[node])
        {
            if (dis[child.first] > curdis + child.second)
            {
                dis[child.first] = curdis + child.second;
                pq.push({curdis + child.second, child.first});
            }
        }
    }

    cout << dis[n] << endl;

    return 0;
}