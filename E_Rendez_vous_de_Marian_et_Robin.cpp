#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector<vector<int>> dij(int s, vector<pair<int, int>> adj[],vector<bool> & mp, int n)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<int>> dis(n, vector<int>(2, 1e18));
    dis[s][mp[s]] = 0;
    pq.push({0, {s, mp[s]}});

    while (!pq.empty())
    {
        int currdis = pq.top().first;
        int node = pq.top().second.first;
        int flag = pq.top().second.second; 
        
        for (auto &[child, weight] : adj[node])
        {
            if ((flag || mp[node] == 1) && dis[child][1] > currdis + weight / 2)
            {
                dis[child][1] = currdis + weight / 2;
                pq.push({dis[child][1], {child, 1}});
            }

            if (dis[child][flag] > currdis + weight)
            {
                dis[child][flag] = currdis + weight;
                pq.push({dis[child][flag], {child, flag}});
            }
        }
    }

    return dis;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, h;
        cin >> n >> m >> h;

        vector<bool> horse( n+1 , 0 );
        for (int i = 0; i < h; i++)
        {
            int x;
            cin >> x;
            horse[x] =1 ;
        }

        vector<pair<int, int>> adj[n+1];
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<vector<int>> dis1 = dij(1, adj, horse, n);
        vector<vector<int>> dis2 = dij(n, adj, horse, n);

        int ans = 1e18;
        for (int i = 1; i <= n; i++)
        {
            int d1 = min(dis1[i][0], dis1[i][1]);
            int d2 = min(dis2[i][0], dis2[i][1]);
            ans = min(ans, max(d1, d2));
        }

        if (ans == 1e18)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
