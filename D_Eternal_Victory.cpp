#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32 main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    int cost = 0;
    for (int i = 1; i < n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
        cost += 2 * w;
    }
    int ans = 0;
    queue<pair<int, int>> q;
    vector<int> dis(n + 1, 1e9);
    dis[1] = 0;
    q.push({1, 0});
    while (!q.empty())
    {
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();
        for (auto child : adj[node])
        {
            if (dis[child.first] > distance + child.second)
            {
                dis[child.first] = distance + child.second;
                ans = max(ans, dis[child.first]);
                q.push({ child.first, dis[child.first]});
            }
        }
    }
    cout << cost - ans << endl;

    return 0;
}