#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int32_t main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> dis(n + 1, 1e16);
    vector<int> ways(n + 1, 0);
    vector<int> maxi(n + 1, 0);
    vector<int> mini(n + 1, 1e16);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dis[1] = 0;
    ways[1] = 1;
    maxi[1] = 0;
    mini[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int curdis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dis[node] < curdis)
            continue;

        for (auto childs : adj[node])
        {

            int child = childs.first;
            int weight = childs.second;

            if (dis[child] > curdis + weight)
            {
                dis[child] = curdis + weight;
                ways[child] = ways[node];
                maxi[child] = maxi[node] + 1;
                mini[child] = mini[node] + 1;
                pq.push( { curdis + weight , child });
            }
            else if (dis[child] == curdis + weight)
            {
                ways[child] = (ways[child] + ways[node]) % mod;
                maxi[child] = max(maxi[child], maxi[node] + 1);
                mini[child] = min(mini[child], mini[node] + 1);
            }
        }
    }

    cout << dis[n] << " " << ways[n] << " " << mini[n] << " " << maxi[n] << endl;

    return 0;
}